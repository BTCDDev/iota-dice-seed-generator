/*
        2017 BTCDDev
        6 Sided Dice Converter to IOTA Seed
        Usage:

               echo "021251432140 ...." | ./iota-dice-seed-generator

               Simulate 243 Dice rolls: cat /dev/urandom | tr -dc 0-5 | head -c 243 | ./iota-dice-seed-generator

       Must pass in 243 rolls, substituting 0 for 6.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
  char rolls[1024] = { 0 };
  fgets(rolls, sizeof rolls, stdin);
  const char ALPHABET[] = "9ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char base3Rolls[243] = { 0 };
  int i = 0, base3RollsCount = 0;
  while(base3RollsCount < 243){
    if((rolls[i] - 48) > 2){
      base3Rolls[base3RollsCount++] = 48 + ((rolls[i] - 48) % 3); //Discard the lower roll
    }
    else{
      base3Rolls[base3RollsCount++] = rolls[i];
    }
    i++;
  }
  char result[82] = { 0 };
  int count = 0;
  for(i=0; i<243; i+=3){
    char temp[4] = { 0 };
    memcpy(temp, &base3Rolls[i], 3);
    long int base10 = strtoul(temp, NULL, 3);
    result[count++] = ALPHABET[base10 % 27];
  }
  printf("%s\n", result);
  return 0;
}