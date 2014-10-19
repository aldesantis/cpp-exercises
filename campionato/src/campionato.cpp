#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::string> nomi_squadre_t;
typedef std::vector<unsigned int> punti_giornata_t;
typedef std::vector<punti_giornata_t> punti_giornate_t;

int trova_indice_squadra(nomi_squadre_t nomi_squadre, std::string nome_squadra)
{
  for (unsigned int i = 0; i < nomi_squadre.size(); i++) {
    if (nomi_squadre[i] == nome_squadra) {
      return i;
    }
  }

  return -1;
}

int trova_punti_squadra(unsigned int indice_squadra, punti_giornate_t punti_giornate)
{
  unsigned int punti = 0;
  unsigned int i;

  for (i = 0; i < punti_giornate.size(); i++) {
    punti += punti_giornate[i][indice_squadra];
  }

  return punti;
}

std::vector<unsigned int> trova_punti_squadre(nomi_squadre_t nomi_squadre, punti_giornate_t punti_giornate)
{
  std::vector<unsigned int> punti_squadre;
  punti_squadre.resize(nomi_squadre.size(), 0);

  for (unsigned int i = 0; i < nomi_squadre.size(); i++) {
    punti_squadre[i] = trova_punti_squadra(i, punti_giornate);
  }

  return punti_squadre;
}

std::vector<unsigned int> trova_vincitori_giornata(unsigned int giornata, punti_giornate_t punti_giornate)
{
  unsigned int i;
  std::vector<unsigned int> vincitori;

  for (i = 0; i < punti_giornate[giornata - 1].size(); i++) {
    if (punti_giornate[giornata - 1][i] == 3) {
      vincitori.push_back(i);
    }
  }

  return vincitori;
}

unsigned int trova_vincitore_campionato(nomi_squadre_t nomi_squadre, punti_giornate_t punti_giornate)
{
  unsigned int i, indice_vincitore, punti_vincitore = 0;

  std::vector<unsigned int> punti_squadre = trova_punti_squadre(nomi_squadre, punti_giornate);

  for (i = 0; i < punti_squadre.size(); i++) {
    if (punti_squadre[i] > punti_vincitore) {
      punti_vincitore = punti_squadre[i];
      indice_vincitore = i;
    }
  }

  return indice_vincitore;
}

void inizializzazione(nomi_squadre_t& nomi_squadre, punti_giornate_t& punti_giornate)
{
  unsigned int numero_giornate, numero_squadre;
  unsigned int i;

  std::cout << "Inserisci il numero di giornate: ";
  std::cin >> numero_giornate;

  std::cout << "Inserisci il numero di squadre: ";
  std::cin >> numero_squadre;

  nomi_squadre.resize(numero_squadre);
  punti_giornate.resize(numero_giornate);

  for (i = 0; i < punti_giornate.size(); i++) {
    punti_giornate[i].resize(numero_squadre);
  }
}

void caricamento(nomi_squadre_t& nomi_squadre, punti_giornate_t& punti_giornate)
{
  unsigned int i, j;

  for (i = 0; i < nomi_squadre.size(); i++) {
    std::cout << "Inserisci il nome della squadra " << i + 1 << ": ";
    std::cin >> nomi_squadre[i];
  }

  std::cout << std::endl;

  for (i = 0; i < punti_giornate.size(); i++) {
    for (j = 0; j < nomi_squadre.size(); j++) {
      do {
        std::cout << "Inserisci punti " << nomi_squadre[j] << " (giornata " << i + 1 << "): ";
        std::cin >> punti_giornate[i][j];
      } while (punti_giornate[i][j] != 0 && punti_giornate[i][j] != 1 && punti_giornate[i][j] != 3);
    }

    std::cout << std::endl;
  }
}

void mostra_vincitori_giornata(nomi_squadre_t nomi_squadre, punti_giornate_t punti_giornate)
{
  unsigned int i;
  unsigned int giornata;
  std::vector<unsigned int> vincitori;

  do {
    std::cout << "Di quale giornata vuoi sapere i vincitori? ";
    std::cin >> giornata;
  } while (giornata < 1 || giornata > punti_giornate.size());

  std::cout << std::endl;

  vincitori = trova_vincitori_giornata(giornata, punti_giornate);

  for (i = 0; i < vincitori.size(); i++) {
    std::cout << "La squadra " << nomi_squadre[vincitori[i]] << " ha vinto la giornata " << giornata << "." << std::endl;
  }
}

void mostra_punti_squadra(nomi_squadre_t nomi_squadre, punti_giornate_t punti_giornate)
{
  std::string nome_squadra;
  int indice_squadra;
  unsigned int punti;

  do {
    std::cout << "Di quale squadra vuoi conoscere i punti? ";
    std::cin >> nome_squadra;

    indice_squadra = trova_indice_squadra(nomi_squadre, nome_squadra);
  } while (indice_squadra == -1);

  std::cout << std::endl;

  punti = trova_punti_squadra(indice_squadra, punti_giornate);

  std::cout << "La squadra " << nome_squadra << " ha totalizzato " << punti << " punti." << std::endl;
}

void mostra_vincitore_campionato(nomi_squadre_t nomi_squadre, punti_giornate_t punti_giornate)
{
  unsigned int indice_vincitore;

  indice_vincitore = trova_vincitore_campionato(nomi_squadre, punti_giornate);
  std::cout << "La squadra che ha vinto il campionato è " << nomi_squadre[indice_vincitore] << "." << std::endl;
}

int main()
{
  nomi_squadre_t nomi_squadre;
  punti_giornate_t punti_giornate;

  unsigned int scelta;

  inizializzazione(nomi_squadre, punti_giornate);
  std::cout << std::endl;

  caricamento(nomi_squadre, punti_giornate);

  do {
    std::cout << "1. Vincitori giornata" << std::endl;
    std::cout << "2. Punti squadra" << std::endl;
    std::cout << "3. Vincitore campionato" << std::endl;
    std::cout << "0. Uscita" << std::endl;

    std::cout << std::endl;

    std::cout << "Inserisci un'opzione: ";
    std::cin >> scelta;

    if (scelta != 0) {
      std::cout << std::endl;
    }

    switch (scelta) {
      case 1:
        mostra_vincitori_giornata(nomi_squadre, punti_giornate);
        break;

      case 2:
        mostra_punti_squadra(nomi_squadre, punti_giornate);
        break;

      case 3:
        mostra_vincitore_campionato(nomi_squadre, punti_giornate);
        break;

      case 0:
        break;

      default:
        std::cout << "Scelta non valida." << std::endl;
    }

    if (scelta != 0) {
      std::cout << std::endl;
    }
  } while (scelta != 0);

  return 0;
}
