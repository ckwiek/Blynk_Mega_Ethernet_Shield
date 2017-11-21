/*
***************************************************************************** *******************

  Vamos ligar o seu LED com Blynk!
  Neste exemplo, usaremos Arduino Mega + Ethernet Shield.
  Adaptado por Eng. Carlos kwiek.
  contato@carloskwiek.com.br
  Vídeo deste sketch aqui: https://youtu.be/Uk95DZH_qWk
  Meu canal no youtube aqui: https://www.youtube.com/channel/UCLZ2cga6-yqz5jtI-XvE7PA?view_as=subscriber

***************************************************** ******************
  Blynk permite criar belas interfaces visuais e arrastar e soltar
  para fazer seus projetos em 5 minutos. E funciona com quase todos os
  hardware.

  Documentos, Tutoriais, tudo: http://www.blynk.cc
  Github: http://github.com/blynkkk
  Comunidade Blynk: http://community.blynk.cc
  Siga-nos: http://www.facebook.com/blynkapp
                               http://twitter.com/blynk_app

  A biblioteca Blynk é licenciada sob licença MIT
  Este código de exemplo está em domínio público.

***************************************************************************** *******************

  Você precisará, em geral:
  - Blynk App (download da AppStore ou do Google Play)
  - Arduino UNO ou placa de microcontrolador similar
  - Decida como conectar o Arduino à Internet
    (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  Há um monte de codigos de exemplos ótimos incluídos para mostrar-lhe como 
  começar. Pense neles como peças LEGO e combine-os como desejar.
  Por exemplo, pegue o codigo Ethernet Shield e combine-o com o
  exemplos, ou escolha um codigo USB e adicione um código de SendData
  por exemplo.
**************************************************************************** *******************
*/

  
  #define BLYNK_PRINT Serial // Enables Serial Monitor
  
  // Usando Arduino Mega e Ethernet Shield (W5100)
  // Se você estiver usando outro Shield, veja outros exemplos
  
  #include <SPI.h>
  #include <Ethernet.h>
  #include <BlynkSimpleEthernet.h>
  #include <SimpleTimer.h>
  
  char auth[] = ""; // Coloque o seu Token Auth aqui. (veja a Etapa 3 acima)
  SimpleTimer timer;
  int buttonSimMillis = 15000; // 1500 milissegundos de simulação
  
  BLYNK_WRITE(V0)
  {
    int blabla = param.asInt();
    if (blabla == 2)
    {
      digitalWrite(13, HIGH);
      timer.setTimeout(buttonSimMillis, buttonOff); // Isso chamará o botão da funçãoOff após
      // buttonSimMillis com a duração especificada acima
  
    }
    else if (blabla == 1)
    {
      digitalWrite(13, HIGH);
    }
    else
    {
      digitalWrite(13, LOW);
    }
  
  }
  
  void buttonOff()
  {
    digitalWrite(13, LOW);
  }
  
  void setup()
  {
    // inicializa o pino digital 13 como saída.
    pinMode(13, OUTPUT);
  
    Serial.begin(9600); // Veja o status da conexão no Serial Monitor
    Blynk.begin(auth); // Aqui, seu Arduino mostra como se conecta ao Blynk Cloud.
  }
  void loop()
  {
    timer.run();
    Blynk.run();  // Toda a Blynk Magic acontece aqui ...
  }
  
  // Você pode colocar aqui seu próprio código ou combiná-lo com outros sketchs.
  
  // Lembre-se  evite a função delay ()
