#define pinIN1 2
#define pinIN2 4
#define pinIN3 7
#define pinIN4 8
#define pinEN1 6
#define pinEN2 10
#define pinBuzzer 11
#define pinLDREsquerdo A0
#define pinLDRCentro A1
#define pinLDRDireito A2

void setup() {
  // put your setup code here, to run once:

pinMode(pinIN1, OUTPUT);
pinMode(pinIN2, OUTPUT);
pinMode(pinEN1, OUTPUT);
pinMode(pinIN3, OUTPUT);
pinMode(pinIN4, OUTPUT);
pinMode(pinEN2, OUTPUT);
pinMode(pinBuzzer, OUTPUT);
pinMode(pinLDREsquerdo, INPUT);
pinMode(pinLDRCentro, INPUT);
pinMode(pinLDRDireito, INPUT);

//calibrando os sensores LDR
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//declarando variáveis dos sensores LDR
int valorLDREsquerdo;
int valorLDRCentro;
int valorLDRDireito;

//lendo os sensores LDR e armazenando nas variáveis  
  valorLDREsquerdo = analogRead(A0);
  //Serial.println(valorLDREsquerdo);
  valorLDRCentro = analogRead(A1);
  //Serial.println(valorLDRCentro);
  valorLDRDireito = analogRead(A2);
  //Serial.println(valorLDRDireito);

//padrão de luminosidade no meu caso (você pode alterálo de acordo com o padrão de luminosidade do seu ambiente)
int luzAmbiente = 750;

//acionando o buzzer
if (valorLDREsquerdo > luzAmbiente || valorLDRCentro > luzAmbiente || valorLDRDireito > luzAmbiente) {
  tone(pinBuzzer, 4000);
  delay(400);
  noTone(pinBuzzer);
  delay(600);
  } else {
  noTone(pinBuzzer);
  }

//lógica dos sensores 
if (valorLDREsquerdo > luzAmbiente || valorLDRCentro > luzAmbiente || valorLDRDireito > luzAmbiente) {
    
    //linha reta
    if (valorLDRCentro > valorLDREsquerdo && valorLDRCentro > valorLDRDireito) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    digitalWrite(pinEN1, 5);
  
    digitalWrite(pinIN3, LOW);
    digitalWrite(pinIN4, HIGH);
    digitalWrite(pinEN2, 5);
    delay(100);
    
    //Pausa
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    digitalWrite(pinIN3, LOW);
    digitalWrite(pinIN4, HIGH);
    analogWrite(pinEN1, 40);
    analogWrite(pinEN2, 40);
    }

    //curva a direita
    if (valorLDRDireito > valorLDRCentro && valorLDRDireito > valorLDREsquerdo) {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, HIGH);
    digitalWrite(pinEN1, 2);
  
    digitalWrite(pinIN3, LOW);
    digitalWrite(pinIN4, HIGH);
    digitalWrite(pinEN2, 5);
    delay(100);
    
    //Pausa
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, HIGH);
    digitalWrite(pinIN3, LOW);
    digitalWrite(pinIN4, HIGH);
    analogWrite(pinEN1, 40);
    analogWrite(pinEN2, 40);
    } 

    //curva a esquerda
    if (valorLDREsquerdo > valorLDRCentro && valorLDREsquerdo > valorLDRDireito) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    digitalWrite(pinEN1, 5);
  
    digitalWrite(pinIN3, HIGH);
    digitalWrite(pinIN4, LOW);
    digitalWrite(pinEN2, 2);
    delay(100);
    
    //Pausa
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    digitalWrite(pinIN3, HIGH);
    digitalWrite(pinIN4, LOW);
    analogWrite(pinEN1, 40);
    analogWrite(pinEN2, 40);
    } 
    
  //caso os sensores LDR não captem luz acima da média 
  } else{
  digitalWrite(pinIN1, HIGH);
  digitalWrite(pinIN2, HIGH);
  digitalWrite(pinIN3, HIGH);
  digitalWrite(pinIN4, HIGH);  
  digitalWrite(pinEN1, HIGH);
  digitalWrite(pinEN2, HIGH);
  }
}
