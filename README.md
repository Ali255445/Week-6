# Week-6
Denne kode illustrere hvor mange felter en skakhest kan ramme uden at besøge samme felt to gange, baseret på dets startposition.
Outputtet viser startpositionen ved at placere tallet i forhold til hvilket felt på et bræt det er. Og så står der hvor mange felter der kunne besøges uden at besøge det samme igen ved hælp af en "greedy" løsning. Altså at der bliver valgt den første mulige løsning hver gang.

START
  ↓
Sæt alle felter som ubesøgt
  ↓
Markér startfelt som besøgt (1)
  ↓
LOOP:
  Prøv hvert af de 8 springer-træk
    ↓
    Kan vi flytte?
       JA → Flyt springer, markér felt, fortsæt
       NEJ → prøv næste træk
  ↓
Hvis ingen træk virker → STOP
  ↓
Returnér antal besøgte felter
