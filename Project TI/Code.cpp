int botao = 2;
int vermelho = 5;
int verde = 3;
int azul = 4;
int contador = 0;
int ledsverdes=random(1,16);
int ledsvermelhos=random(1,16);
int red=5,green=3,blue=4;
int varrimento;
unsigned long resettime= 1000;
int lastbuttonState= HIGH;
int buttonState;
unsigned long debounceDelay = 5;
unsigned long lastDebounceTime = 0;
bool flag=true;
bool flag2 = true;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);

}

void loop(){
  flag=true;
  flag2 = true;
  while(flag2){
    Serial.println("#### Welcome to the big math game! ###");
    Serial.println("Press Button to start!");
  flag2 = false;  
  }

  contador=0;
  while(flag){
  int reading = digitalRead(botao);
    
    if (reading != lastbuttonState){
     lastDebounceTime= millis();
       }
    if ((millis()-lastDebounceTime)< debounceDelay){
      if (reading!= buttonState){
        buttonState=reading;
          if (buttonState != HIGH){
              flag=false;     
        }
      }
    }
  }  
    int resultado=0;
       int ledsverdes=random(0,16);
       int ledsvermelhos=random(0,16);
      for(int i=10;i<=13;i++){
      digitalWrite(i, (ledsvermelhos>> (i-10)) % 2);
      }
      for(int i=6;i<=9;i++){
        digitalWrite(i, (ledsverdes>> (i-6)) % 2);
      }
        
      
      int operacao=random(3,6);
        if(operacao==5){
      digitalWrite(red,1);
          resultado=ledsvermelhos & ledsverdes;
    }
      else if(operacao==4){
          digitalWrite(blue,1);
          resultado=ledsvermelhos | ledsverdes;
    }
      else{
        digitalWrite(green,1);
        resultado=ledsvermelhos ^ ledsverdes;
  }
  int tempoinicial=millis();
  int tempoatual=millis();
  while((tempoatual-tempoinicial)<7000){
  tempoatual=millis();
    int reading = digitalRead(botao);
    if (reading != lastbuttonState){
     lastDebounceTime= millis();
       }
    if ((millis()-lastDebounceTime)< debounceDelay){
      if (reading!= buttonState){
        buttonState=reading;
          if (buttonState != HIGH){
              contador++;
              Serial.println(contador);     
        }
      }
    }
    lastbuttonState=reading;
    if ((millis()-lastDebounceTime)>resettime){
        if (buttonState == LOW){
        Serial.println("O programa vai ser resetado");
        delay(1000);
        loop();
        }
     }
  
   }
      if(contador==resultado){
        Serial.println("Ganhou o jogo!!!!");
          int joao = millis();
        while((millis()-joao)<5000){
            for (int i = 0; i<4;i++){
              digitalWrite(operacao, HIGH);
              digitalWrite(6 + i, (ledsverdes>>i&1));
              digitalWrite(10 + i, (ledsvermelhos>>i&1));
            }
            delay(500);
            for (int i = 0; i<4;i++){
              digitalWrite(operacao, LOW);
              digitalWrite(6 + i, (ledsverdes>>i)&0);
              digitalWrite(10 + i, (ledsvermelhos>>i)&0);
            }
            delay(500);
        }
        varrimento = 1;
        while(varrimento<=3)
        {
          for (int i=0; i<=4; i++){
            digitalWrite(6+i, 1);
            digitalWrite(13-i, 1);
            delay(500);
          }
          for (int i=0; i<=4;i++){
            digitalWrite(9-i, 0);
            digitalWrite(10+i, 0);
            delay(500);
          }
          varrimento++;
        }
          
        digitalWrite(operacao,0);
        
        loop();
      }else{
        Serial.println("Perdeu o jogo");
        for(int i=0;i<=3;i++){
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          digitalWrite(10,LOW);
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(13,LOW);
          digitalWrite(operacao,0);
          delay(1250);
          digitalWrite(operacao,1);
          delay(1250);
        
        }
        digitalWrite(operacao,0);
        loop();
      }

  }



    

  


