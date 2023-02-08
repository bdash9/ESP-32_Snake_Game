void eatSound(){
  tone(buzzer, 4186); // half a second
 // tone(pin, 5274, // E
    //  500); // half a second
 // delay(500);
}
void Play_CrazyFrog()
{
  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note) / sizeof(int)); thisNote++) {

    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(buzzer, CrazyFrog_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(buzzer); //stop music on pin 8
  }
}
void play_GavmeOver(){
 for (int thisNote = 0; thisNote < 8; thisNote++) {


        int noteDuration = 1000 / noteDurations[thisNote];
        tone(buzzer, melody[thisNote], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(buzzer);
      }}
