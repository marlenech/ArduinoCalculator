#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int number1 = 0;
int number2 = 0;
int resultat = 0;
int typeResult;
int result1 = 0;
int result2 = 0;
int result3 = 0;



void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Arduino");

 lcd.setCursor(0, 1);
 lcd.print("Calculator !");
  
  //Effacer l'écran avant de passer à une nouvelle opération  
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);

}

void loop() {
  


//Génération des nombres aléatoires de 0 à 20
number1 = random(0, 20);

  
number2 = random(0, 20);


//Affichage de l'opération et calcul du résultat
lcd.print(number1);
lcd.print(" + ");
lcd.print(number2);
lcd.print(" = ");
resultat = number1 + number2;
Serial.println(resultat);
  

  
//Affichage des résultats (dont 2 faux)
lcd.setCursor(0,1);
lcd.print("a)");
typeResult = random(2);
//Définir type de résultat
  switch(typeResult){
    case 0 :
    result1 = resultat + random(1, 6);
    lcd.print(result1);
    break;
    case 1 :
    result1 = resultat;
    lcd.print(result1);
    break;
  }


  
lcd.setCursor(6, 1);
lcd.print("b)");
  if(result1 == resultat){
    result2 = resultat + random(1, 6);
    if(result2 == result1) {
    lcd.print(result2 + random(1, 2));
    }
    else {
    lcd.print(result2);
    }
   }
   else {
    result2 = resultat;
    lcd.print(result2);
  }
  
  
   
  
  


  
  
lcd.setCursor(12, 1);
lcd.print("c)");
  if(result1 != resultat && result2 != resultat) {
    result3 = resultat;
    lcd.print(result3);
  }
  else {
    result3 = resultat + random(1, 6);
    if(result3 == result1 || result3 == result2){
    result3 = result3 + random(1, 6);
    }
    lcd.print(result3);
    
  }
 
 
  //Effacer l'écran avant de passer à une nouvelle opération  
  delay(10000);
  lcd.clear();
  lcd.setCursor(0,0);
  

 
}
