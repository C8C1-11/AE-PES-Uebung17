// AE-PES-Uebung17.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

int getRadixPower(int run, int radix) {
	return (int)trunc(run / (double)radix);
}

int getNextStep(int run, int radix) {
	// How much radix power do we having?
	int radixPower = getRadixPower(run, radix);
	// Take run number minus radix power sqaured by two,
	// for only having a number between 0 and radix.
	int nextStep = run - (radix * radixPower);
	// In each second turn, we want ... (*)
	int backwards = radixPower % 2;

	// Check if true/not zero.
	if (backwards)
		// (*) ... to calculate the rest of radix minus
		// run as we would go backwards now. :)
		nextStep = radix - nextStep;

	return nextStep;
}

int main()
{
	cout << "steps:";

	// We want 4 times ...
	const int pendulumSwings = 4;
	// ... 10 runs.
	const int radixOfSwing = 10;
	int maxRuns = radixOfSwing * pendulumSwings;
	/* At the end of each backwards turn, we want to skip 0 and 1
	/* These variables stores the to be skipped and skipped runs. */
	int skip = 0;
	int skipped = 0;

	// Iterate those runs.
	for (int run = 1; run <= maxRuns; run++) {
		// Calulate next step and print it out.
		cout << " " << getNextStep(run, radixOfSwing);
		/* We want to check if the next run goes forward again. 
		/* If so, then we skip the next two runs (0,1). */
		skip = (int)trunc(getRadixPower(run + 1, radixOfSwing) / (double)2) * 2;
		// Take skipped runs into account to prevent double skips.
		run += skip - skipped;
		// Save the skips, so that the skips can be 
		// taken into account in next iterations.
		skipped = skip;
	}

	cout << "\n";
	system("pause");
	return 0;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
