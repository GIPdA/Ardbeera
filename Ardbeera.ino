
#include "teensy_config.h"


/* ********************************************************************************* *
 *			Global variables
 * ********************************************************************************* */

uint8_t state = 0, cnt = 0;


/* ********************************************************************************* *
 *			Setup
 * ********************************************************************************* */

/// @brief Setup function, used to initialize the board
///
void setup()
{
  Serial.begin(115200);
  delay(1000);	// For debug to be printed in Arduino serial monitor

  Serial.println("\n   ~ Ardbeera Start ~ ");
  
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, HIGH);

  // Init FlexTimer0

  // System Freq: 48MHz
  // Prescaler: 1:128
  // IT freq: SysF/(Presc * Modulo * TOF counter)

  FTM0_MODE |= (1<<2); // Write protection disabled
  
  //FTM0_MODE |= (1<<0); // FTM enable
  
  FTM0_SC = 0;	// !!NEEDED!! Write to 0 before writing other registers
  
  FTM0_CNT = 0x0000;
  FTM0_CNTIN = 0x0000;
  FTM0_MOD = 0xF424;	// IT freq: 6Hz (48M/(128*62500))
  
  FTM0_SC = FTM_SC_TOIE        // Interrupt enabled
          | FTM_SC_CLKS(0b01)  // Clock source (System clock)
          | FTM_SC_PS(0b111);  // Prescaler (1:128)
  
  // Enable FTM0 IRQ
  NVIC_ENABLE_IRQ(IRQ_FTM0);
  
  FTM0_MODE &= ~(1<<2); // Write protection enabled
}



/* ********************************************************************************* *
 *			Loop
 * ********************************************************************************* */

/// @brief Loop function, repeatedly called
///
void loop()
{
  // Nothing to do
}


/* ********************************************************************************* *
 *			ISRs
 * ********************************************************************************* */

/// @brief FTM0 Overflow ISR handler
///
ISR(ftm0_isr)
{
  FTM0_SC &= ~FTM_SC_TOF;	// Clear TOF flag

  // Divide by 3 to get 1Hz blinking
  if((cnt++ % 3) == 0)	// Glitch at overflow, but we don't care :p
    digitalWrite(ONBOARD_LED, state ^= HIGH);
}


