
# Aktivasyon Fonksiyonları Kütüphanesi

Yapay sinir ağlarında kullanılan temel aktivasyon fonksiyonlarını içeren modern C++ kütüphanesi.

## 📖 Proje Amacı
Bu kütüphane, yapay sinir ağlarında sıkça kullanılan aktivasyon fonksiyonlarını modüler ve genişletilebilir bir şekilde sunar. Temel amaçlar:
- Aktivasyon fonksiyonlarını nesne yönelimli programlama prensipleriyle uygulamak
- Kolay entegre edilebilir bir yapı sunmak
- Test ve debug süreçlerini kolaylaştırmak

## 🛠️ Teknik Özellikler

### Aktivasyon Fonksiyonları
1. **ReLU (Rectified Linear Unit)**
   - Negatif değerleri sıfırlar
   - Pozitif değerleri olduğu gibi geçirir
   - $`f(x) = max(0, x)`$

2. **Sigmoid**
   - Değerleri [0,1] aralığına sıkıştırır
   - $`f(x) = 1 / (1 + e^(-x))`$

3. **Tanh (Hiperbolik Tanjant)**
   - Değerleri [-1,1] aralığına sıkıştırır
   - $`f(x) = (e^x - e^(-x)) / (e^x + e^(-x))`$

4. **Softmax**
   - Vektör girişi alır
   - Olasılık dağılımı üretir
   - Tüm çıktıların toplamı 1'dir
   - $softmax(x_i) = \frac{e^{x_i}}{\sum_{j=1}^{n} e^{x_j}}$

### 📐 Mimari Yapı
- **Arayüzler** (`interfaces/`)
  - `IActivationFunction`: Temel aktivasyon arayüzü
  - `IVectorActivationFunction`: Vektör tabanlı aktivasyonlar için arayüz

- **Fonksiyonlar** (`functions/`)
  - Her aktivasyon fonksiyonu ayrı header dosyasında
  - SOLID prensiplerine uygun tasarım

- **Fabrika** (`factory/`)
  - `ActivationFunctionFactory`: Aktivasyon fonksiyonlarını üreten fabrika sınıfı

## 🔍 Kullanım Örneği
```cpp
#include "activation_functions.h"

using namespace activation;

int main() {
    // Sigmoid fonksiyonu oluştur
    auto sigmoid = ActivationFunctionFactory::createActivation(
        ActivationFunctionFactory::SIGMOID);
    
    // Fonksiyonu kullan
    double sonuc = sigmoid->compute(1.0);
    return 0;
}
```

## 🚀 Geliştirme & Test
- Modern C++ (C++17) özellikleri kullanılmıştır
- CMake ile derleme sistemi
- Icecream kütüphanesi ile gelişmiş debug desteği
- Rastgele veri üretimi ile test imkanı

## 📦 Kurulum
```bash
git clone [repo-url]
cd activation-functions
mkdir build && cd build
cmake ..
make
```

## 🤝 Katkıda Bulunma
- Yeni aktivasyon fonksiyonları eklenebilir
- Performans iyileştirmeleri yapılabilir
- Test senaryoları genişletilebilir

## 📄 Lisans
MIT Lisansı altında dağıtılmaktadır.

---

Bu kütüphane, yapay sinir ağları ve derin öğrenme projelerinde kullanılmak üzere tasarlanmıştır. Modüler yapısı sayesinde kolayca genişletilebilir ve mevcut projelere entegre edilebilir.
