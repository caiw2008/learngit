#include <WiFi.h>

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,22);
IPAddress subnet(255,255,255,0);

const char *ssid = "ESP32_AP_TEST";
const char *password = "12345678";

void setup()
{
  Serial.begin(115200);
  Serial.println();
  
  WiFi.mode(WIFI_AP); //设置工作在AP模式

  WiFi.softAPConfig(local_IP, gateway, subnet); //设置AP地址
  while(!WiFi.softAP(ssid, password)){}; //启动AP
  Serial.println("AP启动成功");

  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP()); // 打印IP地址

  WiFi.softAPsetHostname("myHostName"); //设置主机名
  Serial.print("HostName: ");
  Serial.println(WiFi.softAPgetHostname()); //打印主机名

  Serial.print("mac Address: ");
  Serial.println(WiFi.softAPmacAddress()); //打印mac地址
}

void loop()
{
  delay(1000);
  Serial.println(WiFi.softAPgetStationNum()); //打印客户端连接数
}
