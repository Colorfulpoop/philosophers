# philosophers

• Questo progetto deve essere scritto in C, seguendo la Norma 42. Qualsiasi perdita di memoria, crash, comportamento non definito o errore di norma significa 0 per il progetto.

• Un certo numero di filosofi sono seduti a un tavolo rotondo facendo una delle tre cose: mangiare, pensare o dormire.

• Mentre mangiano, non stanno pensando o dormendo, mentre dormono, non stanno mangiando o pensando e, naturalmente, mentre pensano, non stanno mangiando o dormendo.

• I filosofi si siedono a un tavolo circolare con una grande ciotola di spaghetti al centro.

• Ci sono alcune forchette sul tavolo.

• Poiché gli spaghetti sono difficili da servire e mangiare con una sola forchetta, si assume che un filosofo debba mangiare con due forchette, una per ogni mano.

• I filosofi non devono mai essere affamati.

• Ogni filosofo deve mangiare.

• I filosofi non parlano tra loro.

• I filosofi non sanno quando un altro filosofo sta per morire.

• Ogni volta che un filosofo ha finito di mangiare, lascerà cadere le sue forchette e inizierà a dormire.

• Quando un filosofo ha finito di dormire, inizierà a pensare.

• La simulazione si ferma quando un filosofo muore.

• Ogni programma dovrebbe avere le stesse opzioni: numero_di_filosofi tempo_per_morire tempo_per_mangiare tempo_per_dormire [numero_di_volte_che_ogni_filosofo_deve_mangiare]

◦ numero_di_filosofi: è il numero di filosofi e anche il numero di forchette

◦ tempo_per_morire: è in millisecondi, se un filosofo non inizia a mangiare 'tempo_per_morire' millisecondi dopo l'inizio del suo ultimo pasto o dell'inizio della simulazione, muore

◦ tempo_per_mangiare: è in millisecondi ed è il tempo necessario per un filosofo per mangiare. Durante questo tempo dovrà tenere le due forchette.

◦ tempo_per_dormire: è in millisecondi ed è il tempo che il filosofo trascorrerà dormendo.

◦ numero_di_volte_che_ogni_filosofo_deve_mangiare: l'argomento è facoltativo, se tutti i filosofi mangiano almeno 'numero_di_volte_che_ogni_filosofo_deve_mangiare' la simulazione si fermerà. Se non specificato, la simulazione si fermerà solo alla morte di un filosofo.

• Ogni filosofo dovrebbe avere un numero da 1 a 'numero_di_filosofi'.

• Il filosofo numero 1 è accanto al filosofo numero 'numero_di_filosofi'. Qualsiasi altro filosofo con numero N è seduto tra il filosofo N-1 e il filosofo N + 1.

• Qualsiasi cambio di stato di un filosofo deve essere scritto come segue (con X sostituito dal numero del filosofo e timestamp_in_ms l'istante corrente in millisecondi)
◦ timestamp_in_ms X ha preso una forchetta
