Na ulachę
1.Do poprzedniego jeszcze przydało by się dołożyć tą jedną rzecz której nam zabrakło oraz:
X^n=Xn-1
En=Xn-X^n  (gdzie e to błąd różniczkowy a reszta to kodowanie różniczkowe)
Wzór na spadek energi 
2.Wzór na wartości przewidywane: 
X^n=a1*xn-1+a2*xn-2+….ar*xn-r (gdzie r to rząd predykcji)
Skąd mamy wziąć wartość a ?
A z tego wzorku:
A=[a1,a2…ai] (A składa się z Al i Ap Które są wektorami i są zmiennymi typu double )  A mamy znaleźć takie dla każdej próbki żeby układ równań był spełniony, pomocna będzie tu metoda simplex która da nam te a.
Przydatny wzór na zaokrąglanie liczby:
X^n=floor(X^n+05);
3. W tym punkcie mamy układ równań:
Pierwsze: a1*Xn-1+a2*Xn-2+….+ar*Xn-r=Xn+e1
Drugie:     a1*Xn+a2Xn-1+a3Xn-2+…..+ar*Xn-r+1=Xn+1+e2
                           .
                           .
                           .
                    a1*Xn-1+N+ar*Xn-r+N=Xn+N+e3             (N to liczba próbek w kanale) 
 -> dąży do minimum
(szukamy minimalizacji tej funkcji metodą simplex (czyt. Quick/fast) jest to eleganckie i w miarę szybkie rozwiązanie) <- tego dotyczą nasze labki ogólnie
