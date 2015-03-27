#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main(int argc, char **argv){

    ALLEGRO_DISPLAY *display;
    ALLEGRO_SAMPLE *sample;
    ALLEGRO_BITMAP *background;

    al_init();
    al_init_image_addon();
    al_init_acodec_addon();
    al_install_audio();
    al_reserve_samples(1);

    display = al_create_display(800, 528);

    sample = al_load_sample("fight.wav");
    background = al_load_bitmap("dark.png");

    al_draw_bitmap(background, 0, 0, 0);
    al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

    al_flip_display();

    al_rest(10.0);

    al_destroy_display(display);
    al_destroy_sample(sample);
    al_destroy_bitmap(background);

    return 0;
}
