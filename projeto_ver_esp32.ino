#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
const int led = 22;
int botao = 15;
char comandoCelular;    // declarações
char comandocomputador;
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32"); //informaçoes 
  Serial.println("ligado"); //informar qunado rodar
  pinMode(botao, INPUT);  // definições
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  int estado = digitalRead(botao);
  {
  if(estado == HIGH )
  {
    SerialBT.println("FERIDO");      // Quando o botão é apertado sera inserido a mensagem de ferido no computador
    Serial.write("FERIDO");          // O mesmo mas printando no celular
    
  }
  }
  
   TesteComando();
  delay (500);
}

void TesteComando()              // Teste para mostrar a função de recebimento de dados do esp32
{

  while( Serial.available() > 0 )  // enviar dados pro esp32 pelo computador
  {
     comandocomputador = Serial.read(); // lê o comando
      
     if (comandocomputador == 'L'){   // Se inserir L no celular acenderá o led do arduino
      digitalWrite(led, LOW); 
      Serial.println("Led ligado");
      SerialBT.println("Led ligado");
     }


     if (comandocomputador == 'D'){   // Se inserir D no celular desligará o led do arduino
      digitalWrite(led, HIGH);
      Serial.println("Led Desligado");
      SerialBT.println("Led Desligado");
     }
    delay(100);

  }
  while( SerialBT.available() > 0 )  // enviar dados pro esp32 pelo celular
  {
     comandoCelular = SerialBT.read(); // lê o comando
      
     if (comandoCelular == 'L'){   // Se inserir L no celular acenderá o led do arduino
      digitalWrite(led, LOW); 
      Serial.println("Led ligado");
      SerialBT.println("Led ligado");
     }


     if (comandoCelular == 'D'){   // Se inserir D no celular desligará o led do arduino
      digitalWrite(led, HIGH);
      Serial.println("Led Desligado");
      SerialBT.println("Led Desligado");
     }
    delay(100);

  }
  
}
