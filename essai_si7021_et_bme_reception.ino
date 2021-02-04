#include <Wire.h> // Librairie pour la communication I2C
#include <Adafruit_SSD1306.h>  // ECRAN
#include <Adafruit_GFX.h>      // AFFICHAGE

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);// remplace "display" par Adafruit_SSD1306 et initialise les pixels en X,Y,&mode de transmission
#define OLED_ADDR   0x3C      // adresse I2C du Oled -> 0x3C

void setup()
{
Wire.begin(4); // Rejoindre le bus à l'adresse #4
Wire.onReceive(receiveEvent); // Preparer une fonction spécifique a la reception de donnee
Serial.begin(9600); // Demarrer la liaison serie avec le PC
// initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // permet de commencer une liaison avec Oled
  display.clearDisplay();        // efface l'ecran
  display.display();       // valide l'affichage avec ce quon a fais avant

}
void loop()
{
delay(100);
}

// Fonction qui s execute si quelque chose est present sur l interface
void receiveEvent(int howMany)
{
int x = Wire.read(); // recevoir un chiffre
Serial.println(x); // afficher ce chiffre sur l'interface serie

    display.setTextSize(1);            // defini la taille du texte du nom du capteur
    display.setTextColor(WHITE);       // permet d'ecrire dans la couleur 
    display.setCursor(0, 0);           // positionne le curseur en X,Y  0,4
    display.print("Valeur receptionée");   // affiche le nom du capteur
    display.display();                 // valide l'affichage
    display.setTextSize(2);
    display.setCursor(20, 16);
    display.print(x);        // affiche la valeur de la variable du capteur
    display.display();
    delay(3000);
    display.clearDisplay();           // efface l'ecran
    display.display();
}
