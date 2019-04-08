// ALLEGRO AUDIO TEST
//
// Baseline from allegro tutorial at
//
// https://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Addons/Audio
//
// Need to:
// play sound with baseline - done
// identify available sound cards/devices - strictly c so can wait
// select sound card
// confirm ability to play sound to selected sound device
// select second (concurrent) sound device
// confirm ability to play sound to second sound device
// confirm ability to play different sounds concurrently on both devices
//

#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

int main(int argc, char **argv){
    
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_SAMPLE *sample=NULL;
	
   if(!al_init()){
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

// SELECT SOUND CARD
//
// try allegro.cfg
// allegro.cfg is not automatically read in A5
// try to read config file

// ALLEGRO_CONFIG *al_load_config_file(const char *filename)

ALLEGRO_CONFIG* cfg = al_load_config_file("allegro.cfg");

// const char *al_get_config_value(const ALLEGRO_CONFIG *config, const char *section, const char *key)

printf("%s\n", al_get_config_value(cfg, "audio", "driver")); // should print: alsa
printf("%s\n", al_get_config_value(cfg, "alsa", "device")); // should print: Audio

// Ok, I can read it, now what??

// void al_destroy_config(ALLEGRO_CONFIG *config)

al_destroy_config(cfg);

// try two different cards
// try different devices within a card - may not work on rPi
//        

if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
     return -1;
   }

   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
     return -1;
   }

   if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
   }
	
//   sample = al_load_sample( "footstep.wav" );
   sample = al_load_sample( "pagemove.wav" );

   if (!sample){
      printf( "Audio clip sample not loaded!\n" ); 
      return -1;
   }
	
   display = al_create_display(640, 480);
	
   if(!display){
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   /* Loop the sample until the display closes. */
   al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

   al_rest(5.0);
	
   al_destroy_display(display);
   al_destroy_sample(sample);
   return 0;
}

