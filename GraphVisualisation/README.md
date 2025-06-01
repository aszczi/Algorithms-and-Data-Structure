
# GraphVisualizer

Wizualizacja grafu nieskierowanego w Java z użyciem Swing.


## 1. Opis programu

- Aplikacja wczytuje graf z pliku input.txt (plik w formacie takim, jak na zajęciach: pierwsza linia określa liczbę wierzchołków, kolejne linie to pary określające krawędzie).
- Wierzchołki są rysowane jako okręgi, krawędzie jako liniowe odcinki między nimi.
- Układ wierzchołków: równomierne rozłożenie na obwodzie okręgu.
- Każdy wierzchołek jest podpisany, a krawędzie zaczynają i kończą się dokładnie na obwodzie wierzchołków nie zachodząc na koła ani etykiety.


## 2. Jak zwiększamy czytelność grafu

1. Układ kołowy
    - Unikamy losowego położenia wierzchołków. Zamiast tego każdy wierzchołek umieszczamy na obwodzie okręgu.
    - Kąt obliczamy jako:
      ```
      angle = 2π * (i / n) – π/2
      ```
      gdzie i to indeks wierzchołka, a n to liczba wierzchołków.
    - Pozycja:
      ```
      x_i = centerX + R * cos(angle)
      y_i = centerY + R * sin(angle)
     
      R = min(350, 350 * n/10) i (centerX, centerY) = (400, 400).
      ```
    - Dzięki temu wierzchołki są równomiernie rozłożone, minimalizujemy przecinanie się krawędzi.

2. Krawędzie zaczynają i kończą się na obwodzie wierzchołków
    - Obliczamy wektor miedzy wierzcholkami
      ```
      dx = to.x – from.x
      dy = to.y – from.y
      length = sqrt(dx*dx + dy*dy)
      dx /= length
      dy /= length
      ```
    - Punkty startu i końca linii przesuwamy o promień wierzchołka:
      ```
      startX = from.x + dx * NODE_RADIUS
      startY = from.y + dy * NODE_RADIUS
      endX   = to.x   – dx * NODE_RADIUS
      endY   = to.y   – dy * NODE_RADIUS
      ```
    - Dzięki temu linie nie wchodzą na koła wierzchołków, a etykiety pozostają czytelne.

3. Centralne pozycjonowanie etykiet
    - Wykorzystujemy "FontMetrics" do obliczenia szerokości i wysokości tekstu, aby napisy wierzchołków były zawsze wyśrodkowane.

## 3. Zastosowane algorytmy

1. Układ kołowy
    - Obliczamy pozycję każdego wierzchołka na obwodzie okręgu, dzieląc pełny kąt (2π) przez liczbę wierzchołków.
    - Zmniejsza to liczbę przecinających się krawędzi w porównaniu z losowym rozmieszczeniem.

2. Przesunięcie krawędzi
    - Dzięki normalizacji wektora między dwoma wierzchołkami i przesunięciu punktów początkowego/końcowego o promień koła, linie krawędzi rysowane są od obwodu jednego okręgu do obwodu drugiego.
    - Zapobiega to nachodzeniu linii na wierzchołki.

3. Ręczne rysowanie
    - Panel dziedziczy po "JPanel", a w metodzie "paintComponent(Graphics)" rysujemy: tło → krawędzie → wierzchołki → etykiety.
    - Użyto "Graphics2D" i "RenderingHints" dla wygładzenia krawędzi.


