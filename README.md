BURSA TEKNİK ÜNİVERSİTESİ
BİLGİSAYAR MÜHENDİSLİĞİ 
BLM0111 ALGORİTMALAR VE PROGRAMLAMA DERSİ PROJE ÖDEVİ

ÖĞRENCİLERİN ADI - SOYADI: 
ALP EREN BAL - SAMET ÖZKAN

ÖĞRENCİLERİN GITHUB PROFILLERI:
https://github.com/AlpEren-BAL
https://github.com/samsozkan

DEĞERLİ HOCALARIMIZ:
Dr. Öğr. Üyesi Ergün GÜMÜŞ
Arş. Gör. Esma İBİŞ 
Arş. Gör. Muhammet Ömer Faruk SELVİ

İÇİNDEKİLER:
1) PROJE HAKKINDA ÖZET
2) GÖREV DAĞILIMI
2) PROJE HAZIRLANIRKEN YAPILAN İŞLEMLER
3) PROJEDE KARŞILAŞILAN PROBLEMLER SONUCU YAPILAN İYİLEŞTİRMELER VE DÜZENLEMELER
4) PROJENİN BİZE KATTIKLARI
5) YARDIMCI KAYNAKLAR

PROJE HAKKINDA ÖZET
Projemizin amacı C programlama dilinde yazacağımız kodlarla kullanıcının gireceği metnin hangi dilde olduğunu anlayabilmektir. Bu projede bahsi geçen dillerimiz İngilizce ve Almanca’dır. Taslak kodda verilen bigram ve trigramların frekansları, kullanıcıdan alınan metinde taranarak hesaplanır ve dillerin frekans değerleriyle karşılaştırılır. Elde edilen frekans değerleri hangi dilin frekanslarına daha yakınsa metnin o dille yazıldığı belirtilir. 

GÖREV DAĞILIMI
Alp Eren Bal'a filtrelenen metnin harf sayısının hesaplanması, hesaplanan bigram ve trigram frekanslarının dil frekanslarıyla karşılaştırılması, girilen metnin dilinin belirlenmesi ve raporun hazırlanması görevleri verilmiştir.
Samet Özkan'a Metnin istenilmeyen karakterlerden temizlenmesi, metnin küçük harfe dönüştürülmesi, bigram ve trigram frekanslarının hesaplanması, raporun ve yorum satırlarının revize edilmesi görevleri verilmiştir.

PROJE HAZIRLANIRKEN YAPILAN İŞLEMLER
1) Öncelikle bu proje hazırlanırken yaptığımız ilk iş grubumuzu kurmaktı.
2) Ardından hocalarımızın bize ulaştırdığı belgeler detaylıca incelenerek bu belgelerde yer alan proje ödevinin kuralları, teslimat süresi ve gönderilen taslak detaylıca analiz edildi.
3) Ödevin amacı ve yapılması gerekenler tam olarak anlaşıldıktan sonra görev dağılımı yapıldı ve ilk iş olarak kullanıcıdan alınan metin void filter_str fonksiyonunda filtrelendi.
Bu işlemde [A-Z], [a-z] ve boşluk karakterlerinin haricindeki karakterlerin boşluk karakterlerine çevrilmesi için metindeki her karakter for döngüsüyle sıralı şekilde tarandı.
Bu taramanın yapılması için kullanıcıdan alınan metindeki karakterlerin indis numaralarını alacak olan i değişkeni for döngüsünün içerisinde tanımlandı ve ilk değeri 0'a atandı. Her döngü sonunda i değişkeni 1 arttırıldı.
Döngü koşulunda kullanıcıdan alınan metindeki karakter sayısını veren strlen() fonksiyonu kullanıldı. Metindeki karakterlerin indis değerini alan i değişkeni, metnin son karakterinin indis ( strlen()-1 ) değerini aldığında döngünün durması için koşul olarak i < strlen() koşulu belirlendi.

4) Her karakterin [A-Z], [a-z] aralığında veya boşluk karakteri olup olmadığının kontrolü için for döngüsünün içerisinde if - else if ve else blokları yerine ternary operatorü tercih edildi.
ASCII (decimal) tablosuna göre karakterin
[a-z] aralığında olması için [97,122] aralığında olması,
[A-Z] aralığında olması için [65-90] aralığında olması gerekir.
Karakter, boşluk karakteri ise 32 değerine sahiptir.
Bu bilgiler doğrultusunda ternary operatör kullanılarak koşulların sırayla sınanması sağlandı ve bu üç koşuldan herhangi birisini sağlamayan karakterler boşluk karakterine dönüştürüldü.
Metinde bulunması istenilen karakterler üzerinde ise değişiklik yapılmadı.
Böylece metin filtreleme işlemi tamamlandı.

5) Metinde bulunan bigram ve trigramların sayısının hesaplanması esnasında büyük - küçük harf uyumsuzluğu ile karşılaşmamak adına metindeki tüm harfler tolower_str fonksiyonunda küçük harfe dönüştürüldü.
Bu işlem için <ctype.h> kütüphanesinde bulunan tolower() fonksiyonu, for döngüsü ve iç içe if yapısı kullanıldı.
For döngüsünde koşul olarak karakterin, karakter dizilerinin sonunda bulunan sonlandırıcı karaktere eşit olmama durumu belirlendi.
(str[i] != '\0')
Böylece son indisli karaktere kadar tüm karakterler tarandı.
[A-Z] aralığında olan karakterler küçük harf yapıldı.
Ardından puts() fonksiyonu ile güncellenen metin ekrana bastırıldı.

6) Metinde geçen bigram ve trigramların frekanslarının hesaplanmasında kullanılması için void harf_hesaplama fonksiyonunda metindeki harf sayısı hesaplandı.
Bu işlem için for döngüsü kullanıldı. Metindeki tüm karakterler i < strlen() koşuluyla tarandı ve boşluk karakterine eşit olmayan her karakter için globalde tanımlanan float harf_sayisi değişkeni bir arttırıldı.

7) Metinde geçen bigramların sayısı ve frekansları void calculate_frequencies_bi fonksiyonunda hesaplandı.
Bu işlem için öncelikle aranılan bigramların metinde bulunma sayılarının tutulacağı 10 elemanlı int bigram_sayisi dizisi oluşturuldu ve her indise 0 değeri verildi. 
Sonrasında iç içe for döngüsü oluşturuldu. Taslak kodda verilen bigram dizisi 10 elemanlı olduğu için dıştaki for döngüsünde ilk değeri 0 olan a değişkeni tanımlandı ve a < 10 koşulu belirtildi. Böylece a değişkeninin bigram dizisinin elemanlarının indislerini sırasıyla alması sağlandı.
İçteki for döngüsünde ise ilk değeri 0 olan i değişkeni tanımlandı ve i < strlen() - 1 koşulu belirtildi. Böylece i değişkeninin metindeki son karakter hariç her karakterin indisini sırasıyla alması sağlandı.
If - else yapısı kullanılarak metindeki i ve ++i indisli karakterlerin taslak kodda verilen bigram dizisinin a indisli elemanının 0 ve 1 indisli karakterleriyle eşleşmesi durumunda tanımladığımız int bigram_sayısı dizisinin a indisli elemanının bir artması sağlandı.
Metinde bulunan bigramların miktarları sırasıyla metnin harf sayısının yarısına bölündü ve 100 ile çarpıldı. Bu işlem ile bigramların frekans değerlerinin hesaplanması sağlandı ve hesaplanan frekans değerlerinin tutulduğu float calculated_frequencies dizisinin ilgili indislerine yerleştirildi.
Metinde aranan bigramlar ve hesaplanan frekans değerleri ekrana bastırıldı.

8) Metinde geçen trigramların sayısı ve frekansları void calculate_frequencis_tri fonksiyonunda hesaplandı.
Bu işlem için öncelikle aranılan trigramların metinde geçme sayılarının tutulduğu int trigram_sayisi dizisi oluşturuldu ve her indise 0 değeri verildi. İç içe for döngüsü oluşturuldu ve metindeki i, i+1, ve i+2 indisli karakterlerin trigram dizisinin a indisli elemanının 0,1 ve 2 indisli karakterleriyle eşleşmesi durumunda trigram_sayisi dizininin a indisli elemanı bir arttırıldı.
Metinde bulunan trigramların miktarları sırasıyla metnin harf sayısının üçte birine bölündü ve 100 ile çarpıldı. Böylece aranan trigramların frekans değerleri hesaplandı. 
Bu değerler float calculated_frequencies dizisine 10. indisinden başlanarak yerleştirildi. Ardından trigramlar ve hesaplanan frekans değerleri ekrana bastırıldı.

9) Bigram ve trigram frekanslarının Ingilizce ve Almanca dillerinin frekans değerlerine öklit uzaklıkları void calculate_distances fonksiyonunda hesaplandı.
Bu işlem için int oklit_eng ve int oklit_germ değişkenleri oluşturuldu ve değerleri 0'a eşitlendi. For döngüsü kullanılarak hesaplanan frekanslar ile dillerin frekans değelerinin farkının kareleri bu değişkenlere eklendi. Ardından elde edilen değerler karekök içine alınarak öklit uzaklıkları hesaplandı ve değerler float distances dizisine yerleştirildi.
10) Kullanıcıdan alınan metnin İngilizce mi yoksa Almanca mı olduğu void detect_lang fonksiyonunda kullanıcıya gösterildi. Bu işlem için if-else yapısı kullanıldı. Hesaplanan öklit uzaklığı değeri daha küçük olan dil, metnin dili olarak belirlendi.

11) int main fonksiyonunda gets() fonksiyonu ile kullanıcıdan metin alındı ve char metin değişkenine atandı. Fonksiyonlar sırasıyla çağrıldı.

PROJEDE KARŞILAŞILAN PROBLEMLER SONUCU YAPILAN İYİLEŞTİRMELER VE DÜZENLEMELER
1)	Kullanıcıdan scanf() fonksiyonuyla metin alınmaya çalışıldı ve istenilen metnin tamamı alınamadı. Bunun üzerine gets() fonksiyonu kullanılarak problem çözüldü.
2)	Metin filtreleme işleminde if - else yapısı, ternary operatorü ile değiştirildi.
3)	Metnin harf sayısını hesaplama işleminin bigram ve trigram fonksiyonlarında iki defa yapılması yerine yeni bir fonksiyonda tek seferde yapılması sağlandı.
4)	Trigram frekans hesaplama fonksiyonunda koşul belirtirken ++i ifadesi hatalı hesaplamaya sebebiyet verdiği için i+1 ile değiştirildi.
5)	int veri tipindeki harf sayısı değişkeni float’a çevrilerek ondalıklı frekans değerlerinin elde edilmesi sağlandı.
6)	Koşullarda [A-Z] ve [a-z] karakterlerinin ASCII değerleri, karakterlerin kendileriyle değiştirildi.
7)	Trigram hesaplama işleminde while döngüsü, for döngüsü ile değiştirildi.
8)	Tek deyim içeren yapılardaki kıvırcık parantezler kaldırıldı.
9)	Değişken isimleri, girinti-çıkıntılar ve yorum satırları düzenlendi.


PROJENİN BİZE KATTIKLARI
Ülkemizin ve dünyamızın zor evrelerden geçtiği şu günlerde, evlerimize kapanıp henüz daha sınıf arkadaşlarımızla yüz yüze tanışmamışken bu proje sayesinde tekrar ekip olmayı hatırladık ve çok değerli hocalarımızın öğrettiği bilgilerle bilgilerimizi sınadık. Takıldığımız yerlerde hocalarımızla yaptığımız canlı ders tekrarlarından faydalandık ve bunun bizi gözle görülür biçimde geliştirdiği kanaatindeyiz. Bize değerli bilgilerini aktardıkları için Arş. Gör. Esma İBİŞ ve Arş. Gör. Muhammet Ömer Faruk SELVİ ve Dr. Öğr. Üyesi Ergün GÜMÜŞ hocalarımıza çok teşekkür ederiz.


YARDIMCI KAYNAKLAR
www.stackoverflow.com
www.tutorialspoint.com
www.programiz.com
www.asciitable.com
	
BTU E-Kampus BLM0111 ders videolarından faydalanılmıştır.

ALP EREN BAL & SAMET ÖZKAN

