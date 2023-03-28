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

• Ogni programma dovrebbe avere le stesse opzioni: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

◦ number_of_philosophers : è il numero di filosofi e anche il numero di forchette

◦ time_to_die : è in millisecondi, se un filosofo non inizia a mangiare 'tempo_per_morire' millisecondi dopo l'inizio del suo ultimo pasto o dell'inizio della simulazione, muore

◦ time_to_eat : è in millisecondi ed è il tempo necessario per un filosofo per mangiare. Durante questo tempo dovrà tenere le due forchette.

◦ time_to_sleep : è in millisecondi ed è il tempo che il filosofo trascorrerà dormendo.

◦ number_of_times_each_philosopher_must_eat : l'argomento è facoltativo, se tutti i filosofi mangiano almeno 'numero_di_volte_che_ogni_filosofo_deve_mangiare' la simulazione si fermerà. Se non specificato, la simulazione si fermerà solo alla morte di un filosofo.

• Ogni filosofo dovrebbe avere un numero da 1 a 'number_of_philosophers'.

• Il filosofo numero 1 è accanto al filosofo numero 'number_of_philosophers'. Qualsiasi altro filosofo con numero N è seduto tra il filosofo N-1 e il filosofo N + 1.

• Qualsiasi cambio di stato di un filosofo deve essere scritto come segue (con X sostituito dal numero del filosofo e timestamp_in_ms l'istante corrente in millisecondi)
◦ timestamp_in_ms X has taken a fork  
◦ timestamp_in_ms X is sleeping  
◦ timestamp_in_ms X is thinking  
◦ timestamp_in_ms X died 
• Lo stato stampato non deve essere confuso o intrecciato con lo stato di un altro filosofo.

• Non può passare più di 10 ms tra la morte di un filosofo e la stampa della sua morte.

• Ancora una volta, i filosofi dovrebbero evitare di morire!

---------------------------------------------------------------------------------------------------------------------------------------------------------

Un mutex (abbreviazione di "mutual exclusion", esclusione mutua in italiano) è un meccanismo di sincronizzazione utilizzato per gestire l'accesso concorrente a risorse condivise, come ad esempio variabili o sezioni di codice.

Il funzionamento di un mutex si basa su due operazioni fondamentali: lock (blocco) e unlock (sblocco). Quando un thread richiede l'accesso ad una risorsa condivisa, esso richiede il lock sul mutex associato a tale risorsa. Se il lock non è disponibile perché già acquisito da un altro thread, il thread in attesa entra in stato di attesa bloccato fino a quando il mutex non viene sbloccato da un altro thread che lo sta utilizzando.

Una volta che il thread ha acquisito il lock, può accedere alla risorsa condivisa in modo sicuro, senza il rischio che altri thread accedano alla stessa risorsa contemporaneamente. Quando il thread ha terminato di utilizzare la risorsa condivisa, rilascia il lock sul mutex associato, rendendo disponibile la risorsa ad altri thread che possono richiederla.

L'utilizzo dei mutex è importante per evitare problemi di concorrenza come le condizioni di gara (race condition) o i deadlock, dove due o più thread entrano in uno stato di attesa reciproca in modo da bloccarsi a vicenda.
