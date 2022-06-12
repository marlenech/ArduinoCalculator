// C++ code
//

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int number1 = 0;
int number2 = 0;
int resultat = 0;




void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Arduino");

 lcd.setCursor(0, 1);
 lcd.print("Calculator !");
  
  /* Application randomSeed sur une broche analogique vide
  pour que les nombres soient réellement aléatoires
  (le random est aléatoire mais toujours avec les mêmes nombres
  au démarrage du programme)*/
  randomSeed(A0);
  
  //Effacer l'écran avant de passer à une nouvelle opération  
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);

}

void loop() {

//Génération des nombres aléatoires de 0 à 20
number1 = random(0, 20);
number2 = random(0, 20);

resultat = number1 + number2;
  
//affichage de la question
lcd.print(number1);
lcd.print(" + ");
lcd.print(number2);
lcd.print(" = ");
  
//création d'un tableau pour les 3 réponses possibles
  int tab[] = {resultat+random(1, 3), resultat-random(1,3),resultat};
  const byte N = sizeof(tab)/sizeof(tab[0]);
  byte i=0;

//melange des 3 réponses dans le tableau
    for(i=0; i< N-1; i++) {
      byte j = random(i, N);
      int echange = tab[i];
      tab[i] = tab[j];
      tab[j] = echange;
    }
    //Serial.println(tab[i]);
  
//affichage des réponses
lcd.setCursor(0,1);
lcd.print("a)");
lcd.print(tab[0]);
  
lcd.setCursor(6,1);
lcd.print("b)");
lcd.print(tab[1]);
  
lcd.setCursor(12,1);
lcd.print("c)");
lcd.print(tab[2]);
  
 
//Effacer l'écran avant de passer à une nouvelle opération  
delay(10000);
lcd.clear();
lcd.setCursor(0,0);
  

 
}
