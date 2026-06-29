# Studentų Informacinė Sistema OOP_Marius_Augustinas
VU ISI Objektinio programavimo kurso laboratoriniai darbai

v0.3 — C++ programa, skirta studentų informacijos įvedimui, saugojimui, galutinio pažymio skaičiavimui, rikiavimui, įrašymui į failą ir rezultatų išvedimui pasirinktu formatu (konsolė arba failas). Versijoje v0.3 kodas reorganizuotas į kelis logiškai atskirus modulius (*.h / *.cpp), o klaidų valdymas perkeltas į išimčių (`try`/`catch`) mechanizmą.

## Testavimo rezultatai

Testavimas atliktas po tris kartus kiekvienam failui:
- `studentai10000.txt` nuskaitymas truko vidutiniškai 0,053496 s, rikiavimas truko vidutiniškai 0,038939 s
- `studentai100000.txt` nuskaitymas truko vidutiniškai 0,527913 s, rikiavimas truko vidutiniškai 0,373894 s
- `studentai1000000.txt` nuskaitymas truko vidutiniškai 2,77334 s, rikiavimas truko vidutiniškai 4,61421 s

## Failų struktūra
```
.
├── LICENSE
├── README.md
├── main.h          # Bendra antraštė: struct studentas, konstantos, visos funkcijų deklaracijos
├── mainVector.cpp  # Pagrindinis programos failas (vektorinė realizacija)
├── menu.h / menu.cpp         # Meniu ir pasirinkimų klausimo funkcijos
├── enter.h / enter.cpp       # Rankinio studentų duomenų įvedimo funkcijos
├── generate.h / generate.cpp # Studentų ir pažymių generavimo funkcijos
├── file.h / file.cpp         # Failo skaitymo ir rašymo funkcijos
├── calculate.h / calculate.cpp # Galutinio pažymio skaičiavimo ir rikiavimo funkcijos
├── output.h / output.cpp     # Rezultatų išvesties nukreipimas (konsolė / failas)
└── print.h / print.cpp       # Spausdinimo į konsolę funkcijos
```

Kiekvienas `*.cpp` failas turi savo `*.h` antraštinį failą su atitinkamomis `#include` direktyvomis, kuris yra prijungtas prie bendro `main.h`. Visos struktūros, konstantos ir funkcijų deklaracijos sutelktos `main.h`, kad kiekvienas modulis galėtų jas matyti nekartojant deklaracijų.

## Duomenų struktūros

### `studentas`
Saugo vieno studento informaciją:
- `vardas` — studento vardas
- `pavarde` — studento pavardė
- `namuDarbai` — namų darbų pažymių sąrašas (`vector<int>`)
- `egzaminas` — egzamino pažymys (`minPazymys`–`maxPazymys`)
- `galutinisVid` — galutinis pažymys, skaičiuotas pagal vidurkį
- `galutinisMed` — galutinis pažymys, skaičiuotas pagal medianą

### Konstantos (`main.h`)
- `minPazymys` (1) ir `maxPazymys` (10) — pažymių ribos, naudojamos visose įvesties, generavimo ir failo validavimo funkcijose, kad ribos būtų valdomos vienoje vietoje
- `namuDarbaiSvertis` (0.4) ir `egzaminasSvertis` (0.6) — galutinio pažymio skaičiavimo svoriai
- `lithuanianNames`, `lithuanianSurnames` — vardų ir pavardžių sąrašai, naudojami generavimo funkcijose

## Programos veikimas

### 1. Paleidimas
Programa pradedama `main()` funkcijoje (`mainVector.cpp`):
- Nustatomas konsolės kodavimas į UTF-8 (`SetConsoleOutputCP`, `SetConsoleCP`)
- Išvedamas sveikinimo pranešimas
- Vartotojui pateikiamas meniu
- Visas pagrindinis veiksmų blokas apgaubtas `try`/`catch` bloku — bet kuri programos dalis (skaičiavimas, failo skaitymas/rašymas, spausdinimas, išvesties pasirinkimas) gali saugiai išmesti išimtį, kuri sugaunama vienoje vietoje

### 2. Meniu pasirinkimai — `askMenuChoice()`
- `1` — Įvesti studentus ranka
- `2` — Generuoti tik pažymius (vardai ir pavardės įvedami rankiniu būdu)
- `3` — Generuoti studentų vardus ir pažymius automatiškai
- `4` — Nuskaityti studentus iš failo
- `5` — Baigti darbą

### 3. Studentų įvedimas
- `enterStudentaiVector()` — kaupia studentus į vektorių, po kiekvieno klausia, ar pridėti dar vieną (`y/n`)
- `enterStudentas(n)` — įveda vieno studento duomenis kviesdama pagalbines funkcijas:
  - `enterName(n)` / `enterSurname(n)` — įveda vardą / pavardę (tik raidės, tikrinama `isAllLetters`)
  - `enterNumberOfPazymys(n)` — įveda namų darbų skaičių (≥ 0)
  - `enterPazymiai(n, m)` — įveda kiekvieno namų darbo pažymį (`minPazymys`–`maxPazymys`)
  - `enterEgzaminas(n)` — įveda egzamino pažymį (`minPazymys`–`maxPazymys`)

### 4. Studentų generavimas — `generate.cpp`
- `generateStudentai(n)` — generuoja pilnus studentų duomenis (vardą, pavardę ir pažymius)
- `generateOnlyPazymiai(n)` — vardai ir pavardės įvedami rankiniu būdu, pažymiai generuojami
- Vardai ir pavardės parenkamos iš lietuviškų vardų sąrašų (`lithuanianNames`, `lithuanianSurnames`)
- Pažymiai generuojami atsitiktinai naudojant `std::mt19937` su `std::uniform_int_distribution`
- **Nauja v0.3:** atsitiktinių skaičių generatorius (`std::mt19937`) sukuriamas vieną kartą per programos veikimą per `getRng()` (statinis objektas, grąžinamas per nuorodą) ir pakartotinai naudojamas visose generavimo funkcijose, vietoj naujo `std::random_device` sukūrimo kiekvienam kvietimui — tai pagreitina generavimą didelėms studentų imtims ir užtikrina, kad atsitiktiniai skaičiai tarp skirtingų generavimo funkcijų nesutaptų

### 5. Failo skaitymas ir rašymas — `file.cpp`

**Skaitymas:**
- `enterFileName()` — prašo vartotojo įvesti įvesties failo pavadinimą (turi turėti `.txt` plėtinį)
- `readStudentaiFromFile(filename)` — nuskaito studentus iš `.txt` failo:
  - Iš antraštės eilutės nustato namų darbų stulpelių skaičių (pagal `ND` žymėjimą)
  - Nuskaito kiekvieną studentą: vardą, pavardę, namų darbų pažymius ir egzamino pažymį
  - **Tikrina, ar failas egzistuoja ir pavyko jį atidaryti** (`std::ifstream::is_open()`); jei ne — išmeta `std::runtime_error` su failo pavadinimu
  - Tikrina, ar failas nėra tuščias arba sugadintas (trūksta antraštės eilutės)
  - Tikrina kiekvieną eilutę: ar yra vardas ir pavardė, ar yra visi reikiami namų darbų ir egzamino pažymiai, ar jie patenka į `minPazymys`–`maxPazymys` intervalą — visais klaidos atvejais išmetama `std::runtime_error` su konkrečios eilutės numeriu ir lietuvišku klaidos pranešimu

**Rašymas:**
- `enterOutputFileName()` — prašo vartotojo įvesti išvesties failo pavadinimą (turi turėti `.txt` plėtinį)
- `writeStudentaiToFile(studentai, filename)` — įrašo studentų sąrašą su abiem galutiniais pažymiais į `.txt` failą lentelės formatu; jei failo sukurti nepavyksta, išmetama `std::runtime_error`

### 6. Galutinio pažymio skaičiavimas
Galutinis pažymys skaičiuojamas pagal formulę:
```
galutinis = 0.4 × namų_darbų_vidurkis_arba_mediana + 0.6 × egzamino_pažymys
```
Abu metodai skaičiuojami vienu metu ir saugomi atskiruose laukuose:
- `calculateGalutinisAverage()` — skaičiuoja naudojant **vidurkį** → `galutinisVid`
- `calculateGalutinisMedian()` — skaičiuoja naudojant **medianą** → `galutinisMed`
- `calculateGalutinisVector()` — taiko abu skaičiavimus visiems studentams; jei sąrašas tuščias, išmeta `std::runtime_error`

### 7. Rikiavimas
Po skaičiavimo vartotojas gali pasirinkti rikiavimo kriterijų — `askSortBy()`:
- `1` — pagal vardą (abėcėliškai)
- `2` — pagal pavardę (abėcėliškai)
- `3` — pagal galutinį įvertinimą (vidurkis, mažėjančia tvarka)
- `4` — pagal galutinį įvertinimą (mediana, mažėjančia tvarka)

Rikiavimas atliekamas `sortStudentai()` naudojant `std::sort` su lambda funkcija.

### 8. Rezultatų išvedimas — *(nauja v0.3)*
Anksčiau (v0.2) rezultatas visada buvo spausdinamas tik į konsolę. Versijoje v0.3 vartotojas po skaičiavimo (ir, jei taikoma, rikiavimo) renkasi išvesties formatą — `askOutputChoice()`:
- `1` — Išvesti į konsolę
- `2` — Išvesti į failą

Pasirinkimas perduodamas į naują `outputStudentai(studentai, choice)` funkciją (`output.cpp`), kuri:
- pasirinkus `1` — kviečia `printStudentaiVector()` (`print.cpp`)
- pasirinkus `2` — paklausia išvesties failo pavadinimo (`enterOutputFileName()`) ir kviečia `writeStudentaiToFile()` (`file.cpp`)
- esant nenumatytam pasirinkimui — išmeta `std::runtime_error("Neteisingas pasirinkimas išvesties formatui.")`

Konsolės spausdinimo formatas (`print.cpp`):
```
Vardas               Pavardė              Galutinis (Vid.)     Galutinis (Med.)
-----------------------------------------------------------------------
Tomas                Kazlauskas           7.20                 7.00
Aistė                Petrauskaitė         8.60                 8.40
```

## Klaidų / išimčių valdymas (Exception Handling)

Versijoje v0.3 visos pagrindinio veikimo grandinės klaidos valdomos `std::runtime_error` išimtimis, sugaunamos viename `try`/`catch(const std::exception&)` bloke `mainVector.cpp` faile. Pagrindiniai atvejai:

| Vieta | Sąlyga | Pranešimas |
|---|---|---|
| `readStudentaiFromFile` | Failas neegzistuoja arba nepavyko atidaryti | „Nepavyko atidaryti failo: ..." |
| `readStudentaiFromFile` | Failas tuščias / be antraštės | „Failas tuščias arba sugadintas: ..." |
| `readStudentaiFromFile` | Trūksta vardo/pavardės/pažymio eilutėje | „Eilutėje N trūksta ..." |
| `readStudentaiFromFile` | Pažymys už `minPazymys`–`maxPazymys` ribų | „Eilutėje N pažymys už ribų (1-10): ..." |
| `writeStudentaiToFile` | Nepavyko sukurti išvesties failo | „Nepavyko sukurti failo: ..." |
| `calculateGalutinisVector` | Tuščias studentų sąrašas | „Studentų sąrašas tuščias — nėra ką skaičiuoti." |
| `printStudentaiVector` | Tuščias studentų sąrašas | „Studentų sąrašas tuščias — nėra ko spausdinti." |
| `outputStudentai` | Neteisingas išvesties formato pasirinkimas | „Neteisingas pasirinkimas išvesties formatui." |

Visi pranešimai pateikiami lietuvių kalba, o klaidos `main()` lygmenyje gaudomos taip:
```cpp
catch (const std::exception& e)
{
    std::cerr << "Klaida: " << e.what() << std::endl;
    return 1;
}
```

**Pastaba dėl interaktyvios įvesties:** sąsajos su vartotoju funkcijos (`enterName`, `enterSurname`, `enterPazymys`, `enterEgzaminas`, `enterNumberOfStudents` ir kt.) validuoja įvestį naudojant srauto būsenos tikrinimą (`std::cin.fail()` ir `while` ciklą), o ne `throw`/`catch` mechanizmą — vartotojui tiesiog pakartotinai parodomas raginimas, kol įvestis tampa teisinga. Tuo tarpu duomenų, gaunamų **iš failo**, validacija (`readStudentaiFromFile`) realizuota per išimčių mechanizmą, nes ten klaidos negalima ištaisyti vietoje — reikia nutraukti skaitymą ir informuoti vartotoją.

## Įvesties validacija (apžvalga)
- Vardas / pavardė turi ne raides → `isAllLetters` patikra, kartojama įvestis
- Pažymys ne tarp `minPazymys` ir `maxPazymys` → kartojama įvestis (interaktyviai) arba `std::runtime_error` (skaitant iš failo)
- Namų darbų skaičius neigiamas → kartojama įvestis
- Failo pavadinimas neturi `.txt` plėtinio → kartojama įvestis
- Pasirinkimas `y/n`, meniu numeris ar išvesties formatas netinkamas → kartojama įvestis arba `std::runtime_error`

## Kompiliavimas
```bash
g++ -std=c++17 mainVector.cpp menu.cpp enter.cpp generate.cpp file.cpp calculate.cpp output.cpp print.cpp -o programa
./programa
```

> **Pastaba:** programa naudoja `<windows.h>`, todėl skirta Windows operacinei sistemai.

## Pakeitimai nuo v0.2 → v0.3

- Kodas reorganizuotas į atskirus modulius — kiekviena funkcinė sritis (meniu, įvedimas, generavimas, failai, skaičiavimas, išvestis, spausdinimas) turi savo `*.h`/`*.cpp` porą
- Pridėtas naujas modulis `output.h`/`output.cpp` su `outputStudentai()` — leidžia vartotojui po kiekvieno scenarijaus (rankinis įvedimas, generavimas, skaitymas iš failo) pasirinkti, ar rezultatą rodyti konsolėje, ar rašyti į failą (`askOutputChoice()` meniu funkcijoje)
- Klaidų valdymas perkeltas į `std::runtime_error` išimčių mechanizmą: tikrinama, ar failą pavyko atidaryti / sukurti, ar studentų sąrašas netuščias, ar pasirinkimas teisingas; visos klaidos sugaunamos viename `try`/`catch` bloke `main()` viduje
- Magiški skaičiai `1` ir `10` pakeisti vardinėmis konstantomis `minPazymys` ir `maxPazymys` (`main.h`), naudojamomis visur, kur tikrinamos pažymio ribos
- Atsitiktinių skaičių generavimas optimizuotas — visoms `generate.cpp` funkcijoms naudojamas vienas bendras, vieną kartą inicializuotas `std::mt19937` generatorius (`getRng()`) vietoj naujo `std::random_device` kiekvienam kvietimui
- Pataisyta antraštinio failo apsaugos (header guard) rašybos klaida (`calculate.h`)
- Ciklai per `std::vector` pakeisti į range-based `for` (`for (auto &s : studentai)`), pašalinant signed/unsigned palyginimo įspėjimus
