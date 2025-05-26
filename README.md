# BELOT-SOLO

### Acest proiect este o implementare simpligicata în consolă a jocului de "Belot".
#### Belotul este un joc de carti de origine franceza popular atat in tarile francofone cat si in tari precum Bulgaria, Serbia, Republica Moldova si alte tari din Europa de Est
In implementarea data, jocul se desfasoara intr-o varianta simplificata cu 3 jucatori, un jucator uman si 2 boti.

Jocul are implementate urmatoarele functii:

    ->Afisarea regulilor jocului
    ->Desfasurarea completa a unui joc 
    ->Afisarea rezumatului ultimului joc din executia curenta


# Desfasurarea Jocului
## Etapele unei runde de joc

### 🃏 Împărțirea cărților
* Fiecare jucător primește 8 cărți.
* Pachetul este amestecat și împărțit automat.

### 🗣️ Alegerea atuului (licitația)
* Fiecare jucător are ocazia să accepte atuul propus (prima carte din pachet dupa impartirea primelor 5 carti) sau să refuze.
* Dacă toți refuză, urmează o a doua rundă în care jucătorii pot alege orice altă culoare ca atu.
* Dacă nimeni nu acceptă nici acum, dealerul e obligat sa aleaga.

### ♣️ Rolul atuului
* Culoarea aleasă ca atu determină punctajul cartilor de culoare atu.
* Un atu este mai puternic decat un non-atu

### 🔁 Jocul pe ture
* Se joacă 8 ture.
* Punctele jucatorului se calculeaza dupa formula puncte = round(puncte / 10)

#### În fiecare tură:
* Fiecare jucător joacă o carte, în ordine.
* Jucătorii trebuie să respecte culoarea sau să dea atu dacă nu au sau orice alta carte in lipsa celor necesare.
* Daca declarantul rundei nu a jucat inca una atu, orice alt jucator in prezenta unei alternative nu poate misca un atu.
* Câștigă tura cel care a jucat cea mai puternică carte.
* Cărțile jucate sunt colectate de câștigătorul turei.

#### Penalizari:
* Daca declarantul rundei nu a acumulat cele mai multe puncte primeste -10, punctele fiindu-i transferate jucatorului care a castigat runda.
* Daca un jucator nu a acumulat nici un punct in cadrul

### !!! Asigurate ca encodarea in terminal este UTF-8 !!!
## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- fară variabile globale
- datele membre private(sau protected)
- GitHub Actions trecute
- commit-uri pe Git adecvate si punctuale
- folosirea a funcționalităților limbajului fără sens
- folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
    - folosirea excesivă a claselor friend
    - folosirea excesviă a elementelor statice
- fiecare cerinta va fi punctate 1/2 pe implementare + 1/2 pe faptul ca a fost implementata cu sens

## Cerințe
- [x] definirea a minim **2-3 ieararhii de clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (6p)
    - minim o clasa cu:
        - [x] constructori de inițializare [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
        - [x] constructor supraîncărcat [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-func%C8%9Biilor)
        - [x] constructori de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
        - [x] `operator=` de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-operatorilor)
        - [x] destructor [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
        - [x] `operator<<` pentru afișare (std::ostream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L123)
        - [ ] `operator>>` pentru citire (std::istream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L128)
        - [x] alt operator supraîncărcat ca funcție membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L32)
        - [x] alt operator supraîncărcat ca funcție non-membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L39) - nu neaparat ca friend
    - in derivate
        - [x] implementarea funcționalităților alese prin [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding) și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)
            - aceasta va fi făcută prin **2-3** metode specifice temei alese
            - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați
        - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
        - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
        - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
    - pentru celelalte clase se va definii doar ce e nevoie
    - minim o ierarhie mai dezvoltata (cu 2-3 clase dintr-o clasa de baza)
    - ierarhie de clasa se considera si daca exista doar o clasa de bază însă care nu moștenește dintr-o clasă din altă ierarhie
- [x] cât mai multe `const` [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] funcții și atribute `static` (în clase) [0.5p](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
    - [x] 1+ atribute statice non-triviale
    - [x] 1+ funcții statice non-triviale
- [x] excepții [0.5p](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
    - porniți de la `std::exception`
    - ilustrați propagarea excepțiilor
    - ilustrati upcasting-ul în blocurile catch
    - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] clase template
    - [x] crearea unei clase template [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L08)
    - [x] 2 instanțieri ale acestei clase (0.5p)
- STL [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L07#stl)
    - [x] utilizarea a două structuri (containere) diferite (vector, list sau orice alt container care e mai mult sau mai putin un array)
    - [x] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
- Design Patterns [(0.75p)](https://github.com/Ionnier/poo/tree/main/labs/L08)
    - [x] utilizarea a două șabloane de proiectare

### Observații

* Pot exista depunctări până la 2p pentru diferite aspecte precum:
    - memory leak-uri
    - nefolosirea destructorului virtual la nevoie
    - abuzarea de diferite concepte (toate funcțiile declarate virtual)
    - apelarea de funcții virtual în constructori
