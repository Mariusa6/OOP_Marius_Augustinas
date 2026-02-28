# Studentų Informacinė Sistema OOP_Marius_Augustinas
VU ISI Objektinio programavimo kurso laboratoriniai darbai

v0.2 - C++ programa, skirta studentų informacijos įvedimui, saugojimui, galutinio pažymio skaičiavimui, rikiavimui ir įrašymui į failą.

## Failų struktūra
```
.
├── main.h          # Antraštės failas: bibliotekos, struktūros, funkcijų deklaracijos
├── main.cpp        # Pagrindinis programos failas
├── menu.cpp        # Meniu funkcijos
├── generate.cpp    # Studentų ir pažymių generavimo funkcijos
├── file.cpp        # Failo skaitymo ir rašymo funkcijos
└── print.cpp       # Išvedimo funkcijos
```

## Duomenų struktūros

### `studentas`
Saugo vieno studento informaciją:
- `vardas` — studento vardas
- `pavarde` — studento pavardė
- `namuDarbai` — namų darbų pažymių sąrašas (`vector<int>`)
- `egzaminas` — egzamino pažymys (1–10)
- `galutinisVid` — galutinis pažymys, skaičiuotas pagal vidurkį
- `galutinisMed` — galutinis pažymys, skaičiuotas pagal medianą

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
- `4` — Nuskaityti studentus iš failo
- `5` — Baigti darbą

### 3. Studentų įvedimas

- `enterStudentaiVector()` — kaupia studentus į vektorių, po kiekvieno klausia, ar pridėti dar vieną (`y/n`)
- `enterStudentas(n)` — įveda vieno studento duomenis kviesdama pagalbines funkcijas:
  - `enterName(n)` — įveda vardą (tik raidės)
  - `enterSurname(n)` — įveda pavardę (tik raidės)
  - `enterNumberOfPazymys(n)` — įveda namų darbų skaičių (≥ 0)
  - `enterPazymiai(n, m)` — įveda kiekvieno namų darbo pažymį (1–10)
  - `enterEgzaminas(n)` — įveda egzamino pažymį (1–10)

### 4. Studentų generavimas — `generate.cpp`
- `generateStudentai(n)` — generuoja pilnus studentų duomenis (vardą, pavardę ir pažymius)
- `generateOnlyPazymiai(n)` — vardai ir pavardės įvedami rankiniu būdu, pažymiai generuojami
- Vardai ir pavardės parenkamos iš lietuviškų vardų sąrašų (`lithuanianNames`, `lithuanianSurnames`)
- Pažymiai generuojami atsitiktinai (1–10) naudojant `std::mt19937` su `std::uniform_int_distribution`

### 5. Failo skaitymas ir rašymas — `file.cpp` *(nauja v0.2)*

**Skaitymas:**
- `enterFileName()` — prašo vartotojo įvesti įvesties failo pavadinimą (turi turėti `.txt` plėtinį)
- `readStudentaiFromFile(filename)` — nuskaito studentus iš `.txt` failo:
  - Iš antraštės eilutės nustato namų darbų stulpelių skaičių (pagal `ND` žymėjimą)
  - Nuskaito kiekvieną studentą: vardą, pavardę, namų darbų pažymius ir egzamino pažymį

**Rašymas:**
- `enterOutputFileName()` — prašo vartotojo įvesti išvesties failo pavadinimą (turi turėti `.txt` plėtinį)
- `writeStudentaiToFile(studentai, filename)` — įrašo studentų sąrašą su abiem galutiniais pažymiais į `.txt` failą lentelės formatu

### 6. Galutinio pažymio skaičiavimas
Galutinis pažymys skaičiuojamas pagal formulę:
```
galutinis = 0.4 × namų_darbų_vidurkis_arba_mediana + 0.6 × egzamino_pažymys
```
Skirtingai nuo v0.1, dabar **abu metodai skaičiuojami vienu metu** ir saugomi atskiruose laukuose:
- `calculateGalutinisAverage()` — skaičiuoja naudojant **vidurkį** → `galutinisVid`
- `calculateGalutinisMedian()` — skaičiuoja naudojant **medianą** → `galutinisMed`
- `calculateGalutinisVector()` — taiko abu skaičiavimus visiems studentams

### 7. Rikiavimas — *(nauja v0.2)*
Po skaičiavimo vartotojas gali pasirinkti rikiavimo kriterijų — `askSortBy()`:
- `1` — pagal vardą (abėcėliškai)
- `2` — pagal pavardę (abėcėliškai)
- `3` — pagal galutinį įvertinimą (vidurkis, mažėjančia tvarka)
- `4` — pagal galutinį įvertinimą (mediana, mažėjančia tvarka)

Rikiavimas atliekamas `sortStudentai()` naudojant `std::sort` su lambda funkcija.

### 8. Rezultatų išvedimas — `print.cpp`
Išveda studentų sąrašą lentelės formatu su abiem galutiniais pažymiais:
```
Vardas               Pavardė              Galutinis (Vid.)     Galutinis (Med.)
-----------------------------------------------------------------------
Tomas                Kazlauskas           7.20                 7.00
Aistė                Petrauskaitė         8.60                 8.40
```

## Įvesties validacija
Visos įvesties funkcijos tikrina duomenis ir prašo įvesti iš naujo, jei:
- Vardas / pavardė turi ne raides (`isAllLetters`)
- Pažymys ne tarp 1 ir 10
- Namų darbų skaičius neigiamas
- Failo pavadinimas neturi `.txt` plėtinio
- Pasirinkimas `y/n` yra netinkamas simbolis

## Kompiliavimas
```bash
g++ -std=c++17 main.cpp menu.cpp generate.cpp file.cpp print.cpp -o programa
./programa
```

> **Pastaba:** programa naudoja `<windows.h>`, todėl skirta Windows operacinei sistemai.

## Pakeitimai nuo v0.1

- Pašalintas `avgOrMedian` pasirinkimas — dabar **abu** galutiniai pažymiai skaičiuojami automatiškai ir saugomi atskiruose struktūros laukuose (`galutinisVid`, `galutinisMed`)
- Pridėtas naujas meniu punktas: studentų nuskaitymas iš `.txt` failo
- Pridėtas `file.cpp` su failo skaitymo ir rašymo funkcionalumu
- Pridėtas studentų rikiavimas pagal pasirinktą kriterijų (`sortStudentai`, `askSortBy`)
- Patobulintas atsitiktinių skaičių generavimas: naudojamas `std::uniform_int_distribution`
