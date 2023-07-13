#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

void tulostaLatausAika(double latausAikaTunnit) {
    int tunnit = static_cast<int>(latausAikaTunnit);
    int minuutit = static_cast<int>((latausAikaTunnit - tunnit) * 60);
    int sekunnit = static_cast<int>(((latausAikaTunnit - tunnit) * 60 - minuutit) * 60);

    std::cout << "Arvioitu latausaika: " << tunnit << " tuntia, " << minuutit << " minuuttia, " << sekunnit << " sekuntia" << std::endl;
}

double laskeLatausAika(double tiedostonKokoGB, double latausNopeusMbps) {
    double tiedostonKokoMB = tiedostonKokoGB * 1024;
    double latausNopeusMBps = latausNopeusMbps / 8;
    double latausAikaSekunnit = tiedostonKokoMB / latausNopeusMBps;
    double latausAikaTunnit = latausAikaSekunnit / 3600;

    return latausAikaTunnit;
}

int main() {
    while (true) {
        double tiedostonKokoGB, latausNopeusMbps;

        std::system("cls");

        std::cout << "Syötä tiedoston koko gigatavuina: ";
        std::cin >> tiedostonKokoGB;

        std::cout << "Syötä latausnopeus megabitteinä sekunnissa: ";
        std::cin >> latausNopeusMbps;

        double latausAikaTunnit = laskeLatausAika(tiedostonKokoGB, latausNopeusMbps);

        tulostaLatausAika(latausAikaTunnit);

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}