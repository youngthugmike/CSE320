
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Insert your Pulsers here
  Pulser ((SD("2a"), "I ----------- Initial "),  Init, 'i', 10000);
  Pulser ((SD("3a"), "C ----------- Clock"), Clock, 'c', 10000);

  circuits( SD("1c-4c"), Init, Clock, w, x, y, z );

  // Insert your Probes here
  Probe ( (SD("1e"), "w"), w );
  Probe ( (SD("2e"), "x"), x );
  Probe ( (SD("3e"), "y"), y );
  Probe ( (SD("4e"), "z"), z );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock,
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Insert your declarations for any auxiliary Signals here
  Signal notw, notx, noty, notz, and1, and2, and3, and4, and5, and6, W, X, Y, Z;

  // Insert your DFFs here
  Dff (SD(sd,"1d"), (Init, W, Clock, Zero), w);
  Dff (SD(sd,"2d"), (Zero, X, Clock, Init), x);
  Dff (SD(sd,"3d"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd,"4d"), (Zero, Z, Clock, Init), z);

  // Insert your combinational logic here (Not, And, Or gates)
  Not ( SD(sd, "1a"), w, notw );
  Not ( SD(sd, "2a"), x, notx );
  Not ( SD(sd, "3a"), y, noty );
  Not ( SD(sd, "4a"), z, notz );

  And ( SD(sd, "1b"), (notw, y, notz), and1 );   // AND gates
  And ( SD(sd, "2b"), (notw, notx, noty), and2 );
  And ( SD(sd, "3b"), (noty, notz), and3 );
  And ( SD(sd, "4b"), (notw, noty), Y );
  And ( SD(sd, "5b"), (notw, y), and4 );
  And ( SD(sd, "6b"), (w, z), and5 );
  And ( SD(sd, "7b"), (x, z), and6 );

  Or ( SD(sd, "1c"), (and1, and2), W );    // OR gate*/
  Or ( SD(sd, "2c"), (w, and3), X );
  Or ( SD(sd, "3c"), (and4, and5, and6), Z );
}
