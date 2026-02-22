# Studentų Informacinė Sistema OOP_Marius_Augustinas
VU ISI Objektinio programavimo kurso laboratoriniai darbai

v.pradinė - C++ programa, skirta studentų informacijos įvedimui, saugojimui ir galutinio pažymio skaičiavimui.

## Failų struktūra
```
.
├── main.h       # Antraštės failas: bibliotekos, struktūros
└── main.cpp     # Pagrindinis programos failas: visos funkcijos ir main()
```

## Duomenų struktūros

### `studentas`
Saugo vieno studento informaciją:
- `vardas` — studento vardas
- `pavarde` — studento pavardė
- `namuDarbai` — namų darbų pažymių sąrašas (`vector<int>`)
- `egzaminas` — egzamino pažymys (1–10)
- `galutinis` — apskaičiuotas galutinis pažymys

### `studentasNode`
Vienpusio sąrašo mazgas, saugantis `studentas` ir rodyklę į kitą mazgą (`next`).

## Programos veikimas

### 1. Paleidimas
Programa pradedama `main()` funkcijoje:
- Nustatomas konsolės kodavimas į UTF-8 (`SetConsoleOutputCP`, `SetConsoleCP`)
- Išvedamas sveikinimo pranešimas
- Kviečiamos pagrindinės funkcijos

### 2. Studentų įvedimas — `enterStudentai()`
- Kuria vienpusį sąrašą (`linked list`) studentų saugojimui
- Kiekvienam studentui kviečia `enterStudentas(n)`
- Po kiekvieno studento klausia, ar norima pridėti dar vieną (`t/n`)
- Grąžina rodyklę į sąrašo pradžią (`head`)

### 3. Vieno studento įvedimas — `enterStudentas(int n)`
Kviečia šias pagalbines funkcijas:
- `enterName(n)` — įveda vardą (tik raidės)
- `enterSurname(n)` — įveda pavardę (tik raidės)
- `enterNumberOfPazymys(n)` — įveda namų darbų skaičių (≥ 0)
- `enterPazymiai(n, m)` — įveda kiekvieno namų darbo pažymį (1–10)
- `enterEgzaminas(n)` — įveda egzamino pažymį (1–10)

### 4. Metodo pasirinkimas — `askAverageOrMedian()`
Prieš skaičiuojant galutinius pažymius, programa paklausia vartotojo, kokį metodą naudoti namų darbų rezultatams agreguoti:
- `v` — **vidurkis** (aritmetinis namų darbų pažymių vidurkis)
- `m` — **mediana** (vidurinė reikšmė surikiuotame pažymių sąraše)

### 5. Galutinio pažymio skaičiavimas — `calculateGalutinis()`
Galutinis pažymys skaičiuojamas pagal formulę:
```
galutinis = 0.4 × namų_darbų_vidurkis_arba_mediana + 0.6 × egzamino_pažymys
```
- `calculateGalutinisAverage()` — skaičiuoja naudojant **vidurkį**
- `calculateGalutinisMedian()` — skaičiuoja naudojant **medianą**

`calculateGalutinis()` eina per visą sąrašą ir kiekvienam studentui iškviečia atitinkamą funkciją pagal vartotojo pasirinkimą.

### 6. Rezultatų išvedimas — `printStudentai()`
Išveda studentų sąrašą lentelės formatu (stulpelyje nurodoma, ar naudotas vidurkis ar mediana):
```
Vardas          Pavarde         Galutinis (Vid.)
---------------------------------------------
Jonas           Jonaitis        7.20
Petras          Petraitis       8.60
```

## Įvesties validacija
Visos įvesties funkcijos tikrina duomenis ir prašo įvesti iš naujo, jei:
- Vardas / pavardė turi ne raides (`isAllLetters`)
- Pažymys ne tarp 1 ir 10
- Namų darbų skaičius neigiamas
- Pasirinkimas `t/n` arba `v/m` yra netinkamas simbolis

## Atminties valdymas
Programa naudoja dinaminę atmintį (`new`) susietajam sąrašui. Baigus naudoti sąrašą, atmintį reikia atlaisvinti:
```cpp
studentasNode* current = studentai;
while (current != nullptr) {
    studentasNode* temp = current;
    current = current->next;
    delete temp;
}
```

## Kompiliavimas
```bash
g++ -std=c++17 main.cpp -o programa
./programa
```

> **Pastaba:** programa naudoja `<windows.h>`, todėl skirta Windows operacinei sistemai.
