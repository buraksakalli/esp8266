# esp8266

ESP8266'de HTTPRequest için kullanabilirsiniz.
Göndermek istediğiniz değeri url değişkenine ekleterek POST veya GET metodları ile push edebilirsiniz. 

Örnek kullanım;

int sensorData = analogRead(5);
url += sensorData;
