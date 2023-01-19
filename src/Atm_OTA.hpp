#ifndef ATM_OTA_H
#define ATM_OTA_H

#include <Automaton.h>

class Atm_OTA : public Machine {
protected:
  const char* m_pHostname;
  const char* m_pPassword;

public:
  Atm_OTA( void );

  enum { WAITING, OFF }; // STATES
  enum { ELSE }; // EVENTS
  enum { ENT_WAITING, LOOP_WAITING }; // ACTIONS

  Atm_OTA& begin( const char* pHostname, const char* pPassword );

  int event( int id );

  void action( int id );
};

#endif
