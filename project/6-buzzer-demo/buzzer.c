#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

//void buzzer_init()

//{

  /* 

       Direct timer A output "TA0.1" to P2.6.  

        According to table 21 from data sheet:

          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero

          P2SEL.6 must be 1

        Also: P2.6 direction must be output

  */

  // timerAUpmode();/* used to drive speaker */
  //P2SEL2 &= ~(BIT6 | BIT7);
  //P2SEL &= ~BIT7;
  // P2SEL |= BIT6;

  //P2DIR = BIT6;/* enable output to speaker (P2.6) */

  //}
//void buzzer_set_period(short delay_notes) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */

//{
  //int song_notes[14] = {B, E, G, F, E, B2, A2, Fs, E, G, F, Ds, F, B};

  //  int delay_notes[14] = {1, 1.5, .5, 1, 2, 1, 2.5, 2.5, 1.5, .5, 1, 2, 1, 2.5};
  //song_notes[];
  // delay_notes[];
  //CCR0 = cycles;

  //CCR1 = cycles >> 1;/* one half cycle */

//}
  
//void setup()
//{
  //int size = sizeof(song_notes)/sizeof(int);
  //for (int note = 0; note < size; note++)
    //{
      //int duration = 1000 / delay_notes[note];
      //tone(2, song_notes[note], duration);

      //int pause = duration * 2.5;
      //delay(pause);
      //noTone(2);
      // }
  //}
//void loop()
//{

  //}
