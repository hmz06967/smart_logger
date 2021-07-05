# smart_logger
OBDII Can Bus Smart Fortwo Elektrikli Araba için Veri Kaydedici Projesi

# Akıllı Kaydedici Nedir?

Smart Logger projesi, Smart fortwo elektrikli otomobilden Akü voltajı, akımı, SoC, Hız, sıcaklık vb. verileri toplayan veri kaydedici projesidir. Bu veriler SD kartta saklanır.

Projemi aşağıdaki ön projeden türettim ve [XMC4500 Rahatlama Kiti](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc45_relax_v1/) üzerine uyguladım.

https://hackaday.com/2017/02/28/reverse-engineering-the-smart-fortwo-can-bus

https://hackaday.io/project/19931-smart-fortwo-can-bus-reverse-engineering

Ayrıca 4x20 Karakter LCD'ye sahiptir. Maalesef şematiğim yok çünkü onu dev kit olarak oluşturuyorum. Ancak harici olarak sadece 4x20 I2C ekrana ihtiyaç duyar ve tüm bağlantıların pinleri kaynak kodundan kolaylıkla belirlenebilir.

Bunun dışında yaklaşık bir yıldır Berlin'de kullanılan smart'tan veri topladım. Tüm veriler de depoya dahildir.

Veriler yapay zeka, analiz veya bilimsel amaç için kullanılabilir. Doktora eğitimim sırasında bu verileri analiz etmeyi ve belki de araştırma makalesi için bir AI modeli eğitmeyi planlıyordum. Ancak henüz uğraşacak vaktim olmadı. Serbestçe kullanabilirsiniz, ayrıca işbirliği yapabiliriz. Her şey mümkün. Bana sormaktan çekinmeyin. :)


# Python Scripts

Repo ayrıca, csv formatında depolanan smart'tan verileri çizmek için bazı python betikleri içerir. Aşağıda toplanan verilerden bazı grafikleri görebilirsiniz.

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig5.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig2.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig7.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig6.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig1.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig3.png)

![alt text](https://github.com/ErhanYILMAZ/smart_logger/blob/main/figures/fig4.png)
