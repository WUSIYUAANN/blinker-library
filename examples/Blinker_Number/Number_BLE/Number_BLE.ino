/* *****************************************************************
 *
 * Download latest Blinker library here:
 * https://github.com/blinker-iot/blinker-library/archive/master.zip
 * 
 * 
 * Blinker is a platform with iOS and Android apps to 
 * control embedded hardware like Arduino, Raspberrt Pi.
 * You can easily build graphic interfaces for all your 
 * projects by simply dragging and dropping widgets.
 * 
 * Docs: https://doc.blinker.app/
 *       https://github.com/blinker-iot/blinker-doc/wiki
 * 
 * *****************************************************************
 * 
 * Blinker 库下载地址:
 * https://github.com/blinker-iot/blinker-library/archive/master.zip
 * 
 * Blinker 是一个运行在 IOS 和 Android 上用于控制嵌入式硬件的应用程序。
 * 你可以通过拖放控制组件，轻松地为你的项目建立图形化控制界面。
 * 
 * 文档: https://doc.blinker.app/
 *       https://github.com/blinker-iot/blinker-doc/wiki
 * 
 * *****************************************************************/

#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Blinker.h>

#define Number_1 "NUMKey"

BlinkerNumber Number1(Number_1);

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin();
}

void loop()
{
    Blinker.run();

    if (Blinker.available()) {
        BLINKER_LOG("Blinker.readString(): ", Blinker.readString());

        Blinker.vibrate();
        
        uint32_t BlinkerTime = millis();
        Blinker.print(BlinkerTime);
        Blinker.print("millis", BlinkerTime);

        Number1.icon("icon_1");
        Number1.color("#FFFFFF");
        Number1.unit("ms");
        Number1.print(BlinkerTime);

        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}
