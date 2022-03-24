int sound_sensor = A2; // assign to pin A2

void setup()
{
  Serial.begin(115200); // begin Serial Communication
}

void loop()
{
  int soundValue = 0; // create variable to store the sum of 32 different readings
  // why 32 ? each value is between 0 and 1023 and our integer has
  // a max value of 32768
  for (int i = 0; i < 32; i++) // create a for loop to read
  {
    soundValue += analogRead(sound_sensor); // read the sound sensor
  }
  // Compute average of 32 values
  soundValue = soundValue / 32;
  Serial.println(soundValue); // print the value of sound sensor

  // if a value higher than 500 is registered, we will print the following
  // this is done so that we can clearly see if the threshold is met
  if (soundValue > 300)
  {
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");
  }
  delay(50); // a shorter delay between readings
}
