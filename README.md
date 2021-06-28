##  **Tema**
Se dorește implementarea unei aplicații care sa permita gestionarea conturilor
deschise la banca X. Fiecare cont bancar are obligatoriu un detinator, o data a deschiderii lui și un sold.  In cazul conturilor de economii, trebuie retinuta si rata dobanzii (care poate fi pe 3 luni, pe 6 luni sau la un an), precum și un istoric al reactualizarii soldurilor de la deschidere și pană in prezent.
In cazul  in care deținătorul optează pentru un cont curent, el beneficiază de un număr de tranzacții gratuite și altele contra cost (de exemplu orice depunere este gratuită, dar retragerea poate sa coste dacă s-a depășit numărul de tranzacții gratuite, sau e făcută de la bancomatele altor bănci; sau orice cumparatura online are un cost, etc.). Simulati cat mai corect activitatea băncii X.
Structura de date: unordered_map sau unordered_set <id_cont, list sau vector.

**Cerinta**
- utilizarea sabloanelor (template)
-  utilizarea STL
- utilizarea variabilelor, funcțiilor statice, constantelorși a unei functii const
- utilizarea conceptelor de RTTI (ex: upcast & dynamic_cast)
- tratarea excepțiilor (try-catch)
- citirea informațiilor complete a n obiecte, memorareași afișarea acestora

**Cerința suplimentară:**
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template GestionareConturi care sa conțină informații despre banca
X. Clasa conține indexul unui cont (incrementat automat la adaugarea unuia nou prin
supraincarcarea operatorului +=) și o structură de date.
- Să se construiască o specializare pentru tipul Cont_Economii care sa afișeze toate conturile de
economii care au rata dob nzii la 1 an.
