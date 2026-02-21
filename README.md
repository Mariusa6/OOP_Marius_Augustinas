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
Susietojo sąrašo mazgas, saugantis `studentas` ir rodyklę į kitą mazgą (`next`).

## Programos veikimas

### 1. Paleidimas
Programa pradedama `main()` funkcijoje:
- Nustatomas konsolės kodavimas į UTF-8 (`SetConsoleOutputCP`, `SetConsoleCP`)
- Išvedamas sveikinimo pranešimas
- Kviečiamos pagrindinės funkcijos

### 2. Studentų įvedimas — `enterStudentai()`
- Kuria susietąjį sąrašą (`linked list`) studentų saugojimui
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

### 4. Galutinio pažymio skaičiavimas — `updateGalutinis()` / `calculateGalutinis()`
Galutinis pažymys skaičiuojamas pagal formulę:

```
galutinis = 0.4 * namų_darbų_vidurkis + 0.6 * egzamino_pažymys
```

`updateGalutinis()` eina per visą sąrašą ir kiekvienam studentui iškviečia `calculateGalutinis()`.

### 5. Rezultatų išvedimas — `printStudentai()`
Išveda studentų sąrašą lentelės formatu:

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
- Pasirinkimas `t/n` yra netinkamas simbolis

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
g++ main.cpp -o programa
./programa
```

> **Pastaba:** programa naudoja `<windows.h>`, todėl skirta Windows operacinei sistemai.
