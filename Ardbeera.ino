/**
* @file Ardbeera.ino
* @brief Fichier de base
*
* @date 4 février 2013
* @author BBenj
*/

#include "teensy_config.h"

/* ********************************************************************************* *
 *			Global variables
 * ********************************************************************************* */


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


