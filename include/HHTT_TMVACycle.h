// Dear emacs, this is -*- c++ -*-
// $Id: TopTagTMVACycle.h,v 1.1 2012/06/05 14:45:24 rkogler Exp $
#ifndef HHTT_TMVACycle_H
#define HHTT_TMVACycle_H

// SFrame include(s):
#include "include/AnalysisCycle.h"

/**
 *   @short Example of an analysis cycle
 *
 *          This is an example of an analysis cycle. It can be used
 *          as a template for writing your own analysis. Also should
 *          be used for quick cross checks of the system setup.
 *
 *  @author Roman Kogler
 *  @version $Revision: 1.1 $
 */

class HHTT_TMVACycle : public AnalysisCycle {

public:
  /// Default constructor
  HHTT_TMVACycle();
  /// Default destructor
  ~HHTT_TMVACycle();

  /// Function called at the beginning of the cycle
  void BeginCycle() throw( SError );
  /// Function called at the end of the cycle
  void EndCycle() throw( SError );

  /// Function called at the beginning of a new input data
  void BeginInputData( const SInputData& ) throw( SError );
  /// Function called after finishing to process an input data
  void EndInputData  ( const SInputData& ) throw( SError );

  /// Function called after opening each new input file
  void BeginInputFile( const SInputData& ) throw( SError );

  /// Function called for every event
  void ExecuteEvent( const SInputData&, Double_t ) throw( SError );

private:
  //
  // Put all your private variables here
  //
  string m_beta;
  // Macro adding the functions for dictionary generation
  ClassDef( HHTT_TMVACycle, 0 );

}; // class TopTagTMVACycle

#endif // TopTagTMVACycle_H

