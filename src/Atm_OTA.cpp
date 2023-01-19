#include "Atm_OTA.hpp"
#include <ArduinoOTA.h>

Atm_OTA::Atm_OTA( void ) : Machine(){
  m_pHostname = NULL;
  m_pPassword = NULL;
};

Atm_OTA& Atm_OTA::begin( const char* pHostname, const char* pPassword ) {
  const static state_t state_table[] PROGMEM = {
    /*            ON_ENTER      ON_LOOP         ON_EXIT    ELSE */
    /* ON  */     ENT_WAITING,  LOOP_WAITING,   -1,        -1,
  };
  Machine::begin( state_table, ELSE );

  m_pHostname = pHostname;
  m_pPassword = pPassword;

  ArduinoOTA.setHostname( m_pHostname );
  ArduinoOTA.setPassword( m_pPassword );

  ArduinoOTA.begin();

  return *this;
}

int Atm_OTA::event( int id ) {
  return 0;
}

void Atm_OTA::action( int id ){
  switch( id ){
  case LOOP_WAITING:
    ArduinoOTA.handle();
    break;
  }
}

