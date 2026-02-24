# Studentų Informacinė Sistema OOP_Marius_Augustinas
VU ISI Objektinio programavimo kurso laboratoriniai darbai

v0.1 - C++ programa, skirta studentų informacijos įvedimui, saugojimui ir galutinio pažymio skaičiavimui.

## Failų struktūra
```
.
├── main.h          # Antraštės failas: bibliotekos, struktūros, funkcijų deklaracijos
├── mainC.cpp       # Pagrindinis failas su masyvo (C-style array) implementacija
├── mainVector.cpp  # Pagrindinis failas su std::vector implementacija
├── menu.cpp        # Meniu funkcijos
├── generate.cpp    # Studentų ir pažymių generavimo funkcijos
└── print.cpp       # Išvedimo funkcijos
```

## Duomenų struktūros

### `studentas`
Saugo vieno studento informaciją:
- `vardas` — studento vardas
- `pavarde` — studento pavardė
- `namuDarbai` — namų darbų pažymių sąrašas (`vector<int>`)
- `egzaminas` — egzamino pažymys (1–10)
- `galutinis` — apskaičiuotas galutinis pažymys

## Programos veikimas

### 1. Paleidimas
Programa pradedama `main()` funkcijoje:
- Nustatomas konsolės kodavimas į UTF-8 (`SetConsoleOutputCP`, `SetConsoleCP`)
- Išvedamas sveikinimo pranešimas
- Vartotojui pateikiamas meniu

### 2. Meniu pasirinkimai — `askMenuChoice()`
- `1` — Įvesti studentus ranka
- `2` — Generuoti tik pažymius (vardai ir pavardės įvedami rankiniu būdu)
- `3` — Generuoti studentų vardus ir pažymius automatiškai
- `4` — Baigti darbą

### 3. Studentų įvedimas

**`mainC.cpp`** — naudoja C stiliaus masyvą (`studentas*`):
- `enterStudentaiArray(n)` — sukuria dinaminį masyvą ir užpildo jį kviesdama `enterStudentas(n)`

**`mainVector.cpp`** — naudoja `std::vector`:
- `enterStudentaiVector()` — kaupia studentus į vektorių, po kiekvieno klausia, ar pridėti dar vieną

### 4. Vieno studento įvedimas — `enterStudentas(int n)`
Kviečia šias pagalbines funkcijas:
- `enterName(n)` — įveda vardą (tik raidės)
- `enterSurname(n)` — įveda pavardę (tik raidės)
- `enterNumberOfPazymys(n)` — įveda namų darbų skaičių (≥ 0)
- `enterPazymiai(n, m)` — įveda kiekvieno namų darbo pažymį (1–10)
- `enterEgzaminas(n)` — įveda egzamino pažymį (1–10)

### 5. Studentų generavimas — `generate.cpp`
- `generateStudentai(n)` — generuoja pilnus studentų duomenis (vardą, pavardę ir pažymius)
- `generateOnlyPazymiai(n)` — vardai ir pavardės įvedami rankiniu būdu, pažymiai generuojami
- Vardai ir pavardės parenkamos iš lietuviškų vardų sąrašų (`lithuanianNames`, `lithuanianSurnames`)
- Pažymiai generuojami atsitiktinai (1–10) naudojant `std::mt19937`

### 6. Metodo pasirinkimas — `askAverageOrMedian()`
Prieš skaičiuojant galutinius pažymius, programa paklausia vartotojo, kokį metodą naudoti namų darbų rezultatams agreguoti:
- `v` — **vidurkis** (aritmetinis namų darbų pažymių vidurkis)
- `m` — **mediana** (vidurinė reikšmė surikiuotame pažymių sąraše)

### 7. Galutinio pažymio skaičiavimas
Galutinis pažymys skaičiuojamas pagal formulę:
```
galutinis = 0.4 × namų_darbų_vidurkis_arba_mediana + 0.6 × egzamino_pažymys
```
- `calculateGalutinisAverage()` — skaičiuoja naudojant **vidurkį**
- `calculateGalutinisMedian()` — skaičiuoja naudojant **medianą**
- `calculateGalutinisArray()` — taiko skaičiavimą C stiliaus masyvui
- `calculateGalutinisVector()` — taiko skaičiavimą `std::vector`

### 8. Rezultatų išvedimas — `print.cpp`
Išveda studentų sąrašą lentelės formatu (stulpelyje nurodoma, ar naudotas vidurkis ar mediana):
```
Vardas               Pavardė              Galutinis (Vid.)
---------------------------------------------
Tomas                Kazlauskas           7.20
Aistė                Petrauskaitė         8.60
```

## Įvesties validacija
Visos įvesties funkcijos tikrina duomenis ir prašo įvesti iš naujo, jei:
- Vardas / pavardė turi ne raides (`isAllLetters`)
- Pažymys ne tarp 1 ir 10
- Namų darbų skaičius neigiamas
- Pasirinkimas `y/n` arba `v/m` yra netinkamas simbolis

## Atminties valdymas
`mainC.cpp` versijoje naudojama dinaminė atmintis (`new[]`) masyvui. Baigus darbą, atmintis atlaisvinama:
```cpp
delete[] studentai;
```
`mainVector.cpp` versijoje atminties valdymą automatiškai tvarko `std::vector`.

## Kompiliavimas
```bash
# C masyvo versija
g++ -std=c++17 mainC.cpp menu.cpp generate.cpp print.cpp -o programaC

# Vector versija
g++ -std=c++17 mainVector.cpp menu.cpp generate.cpp print.cpp -o programaVector
```

> **Pastaba:** programa naudoja `<windows.h>`, todėl skirta Windows operacinei sistemai.
