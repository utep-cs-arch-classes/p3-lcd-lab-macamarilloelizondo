#ifndef buzzer_included
#define buzzer_included

#define A 55
#define As 58
#define B 61
//#define C 654
#define Cs 69
#define D 36
#define Ds 38
#define E 41
#define F 43
#define Fs 46
#define G 49
#define Gs 51
#define A2 110
#define A2s 116
#define B2 123
#define C3 130

#define  Bb    2146

#define  b     2024

#define  c     1912

#define  db    1805

#define  d     1703

#define  eb    1608

#define  e     1517

#define  f     1432

#define  gb    1351

#define  g     1276

#define  ab    1233

#define  a     1136

#define  bb    1073

#define  B     1012

#define  C     956

#define  Db    902

#define  D     851





// Define a special note, 'R', to represent a rest

#define  R     0



int speakerOut = 9;

int ledPin1=12;

int ledPin2=13;



void setup() {

  pinMode(speakerOut, OUTPUT);

  pinMode(ledPin1, OUTPUT);

  pinMode(ledPin2, OUTPUT);

}





// MELODY and TIMING  =======================================

//  melody[] is an array of notes, accompanied by beats[],

//  which sets each note's relative length (higher #, longer note)

int melody[] = {  b,  e,  g, gb,  e,  B,  a, gb,  e,  g, gb, eb,  f,  b,  b,  e,  g,  gb,  e,  B,  D,  Db,  C,  ab,  C,  B,  bb,  gb,  g,  e,   g,  B,  g,  B,  g,  C,  B,  bb,  gb,  g,  B, 

int beats[]  = { 32, 64, 16, 32, 64, 32, 64, 64, 64, 16, 32, 64, 32, 64, 32, 64, 16,  32, 64, 32, 64,  32, 64,  32, 64, 32,  64,  32, 32, 128, 32, 64, 32, 64, 32, 64, 32,  64,  32, 64, 16,  32,  64, 32, 128, 32, 64, 32, 64, 32, 64,  32, 64,  32, 64, 32,  64,  32, 32, 128, 8 };

int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.



		  // Set overall tempo

long tempo = 10000;

		  // Set length of pause between notes

int pause = 1000;

		  // Loop variable to increase Rest length

int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES



		  // Initialize core variables

int tone_ = 0;

int beat = 0;

long duration  = 0;



		  // PLAY TONE  ==============================================

		  // Pulse the speaker to play a tone for a particular duration

void playTone() {

  long elapsed_time = 0;

  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has

		      //  played less long than 'duration', pulse speaker HIGH and LOW

    while (elapsed_time < duration) {
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);



      // DOWN

      digitalWrite(speakerOut, LOW);

      delayMicroseconds(tone_ / 2);



      // Keep track of how long we pulsed

      elapsed_time += (tone_);

    }

  }



  else { // Rest beat; loop times delay

    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count

      delayMicroseconds(duration);

    }

  }

}



		  // LET THE WILD RUMPUS BEGIN =============================

		  void loop() {

		    // Set up a counter to pull from melody[] and beats[]

		    for (int i=0; i<MAX_COUNT; i++) {

		      tone_ = melody[i];

		      beat = beats[i];



		      duration = beat * tempo; // Set up timing



		      if (duration>=340000){

			digitalWrite(ledPin1,HIGH);

			digitalWrite(ledPin2,LOW);

		      }else{

			digitalWrite(ledPin1,LOW);

			digitalWrite(ledPin2,HIGH);

		      }

		      playTone();

		      // A pause between notes...

		      delayMicroseconds(pause);

		    }

		  }
			  
		  
//int song_notes[14] = {B, E, G, F, E, B2, A2, Fs, E, G, F, Ds, F, B};

//int delay_notes[14] = {1, 1.5, .5, 1, 2, 1, 2.5, 2.5, 1.5, .5, 1, 2, 1, 2.5};

#endif // included
