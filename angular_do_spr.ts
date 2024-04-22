import { TmplAstDeferredBlockLoading } from '@angular/compiler';
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { table } from 'node:console';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet],
  templateUrl: 'powtorka.html',
  styleUrl: './app.component.css',
})
export class AppComponent {
  //Zadanie 1
  text: string = '';
  rok: number = 0;
  sprawdz(): void {
    this.rok = parseInt(
      (document.getElementById('rok') as HTMLInputElement).value
    );
    if (this.rok > 1582) {
      if (this.rok % 100 == 0 && this.rok % 400 == 0) {
        this.text = this.rok + ' Jest rokiem przestepnym!';
      } else if (this.rok % 4 == 0 && this.rok % 100 != 0) {
        this.text = this.rok + ' Jest rokiem przestepnym!';
      } else {
        this.text = this.rok + ' Nie jest rokiem przestepnym!';
      }
    } else {
      this.text = this.rok + ' Nie jest rokiem przestepnym!';
    }
  }
  //Zadanie 2
  kasa: string = '';
  km: number = 0;
  licz(): void {
    this.km = parseInt(
      (document.getElementById('trasa') as HTMLInputElement).value
    );
    if (this.km < 16) {
      this.kasa = 'Cena za przejazd ' + this.km + ' wynosi: 3zł';
    } else if (this.km < 41) {
      let tmp = 0.2 * this.km;
      tmp += 1.5;
      this.kasa = 'Cena za przejazd ' + this.km + ' wynosi: ' + tmp + 'zł';
    } else {
      let tmp = 0.1 * this.km;
      tmp += 1.0;
      this.kasa = 'Cena za przejazd ' + this.km + ' wynosi: ' + tmp + 'zł';
    }
  }
  //Zadanie 3
  ciag: string = '';
  liczba: number = 0;
  kw(): void {
    this.liczba = parseInt(
      (document.getElementById('l') as HTMLInputElement).value
    );
    this.ciag += this.liczba + ' ';
    for (let i = 0; i < 9; i++) {
      this.liczba *= this.liczba;
      this.ciag += this.liczba + ' ';
    }
  }
  //Zadanie 4
  los: string = '';
  min: number = 0;
  max: number = 0;
  losowe(): void {
    this.min = parseInt(
      (document.getElementById('min') as HTMLInputElement).value
    );
    this.max = parseInt(
      (document.getElementById('max') as HTMLInputElement).value
    );
    let tab = [];
    for (let i = 0; i < 10; i++) {
      tab.push(
        Math.floor(Math.random() * (this.max - this.min + 1) + this.min)
      );
    }
    let suma = 0;
    for (let i = 0; i < 10; i++) {
      suma += tab[i];
    }
    let srednia = suma / 10;
    this.los = 'Suma liczb: ' + suma + ' Srednia liczb: ' + srednia;
  }
  //Zadanie 5
  tablica: number[] = [];
  tmp: number[] = [];
  txt: string = '';

  nieparzysta(a: number): boolean {
    if (a % 2) {
      return true;
    } else {
      return false;
    }
  }
  parzysta(a: number): boolean {
    if (a % 2 == 0) {
      return true;
    } else {
      return false;
    }
  }
  dodaj(): void {
    //a
    this.tablica.push(
      parseInt((document.getElementById('n') as HTMLInputElement).value)
    );
    //b
    let min = this.tablica[0];
    let max = this.tablica[0];
    for (let i = 1; i < this.tablica.length; i++) {
      if (this.tablica[i] < min) {
        min = this.tablica[i];
      }
      if (this.tablica[i] > max) {
        max = this.tablica[i];
      }
    }
    //c
    let sr = 0;
    for (let i = 0; i < this.tablica.length; i++) {
      sr += this.tablica[i];
    }
    sr /= this.tablica.length;
    //d
    let liczba3 = 0;
    for (let i = 0; i < this.tablica.length; i++) {
      if (this.tablica[i] == 3) {
        liczba3++;
      }
    }
    //e
    this.tablica.sort((a, b) => a - b);
    //f
    let mediana = this.tablica[Math.ceil(this.tablica.length / 2) - 1];
    if (this.tablica.length % 2 == 0) mediana += 0.5;

    //g
    let Tab_Min = [];
    let Tab_Max = [];
    Tab_Min[0] = this.tablica[0];
    Tab_Max[0] = this.tablica[this.tablica.length - 1];
    if (this.tablica.length >= 3) {
      Tab_Min[1] = this.tablica[1];
      Tab_Max[1] = this.tablica[this.tablica.length - 2];
      Tab_Min[2] = this.tablica[2];
      Tab_Max[2] = this.tablica[this.tablica.length - 3];
    } else {
      Tab_Min[1] = this.tablica[1];
      Tab_Max[1] = this.tablica[this.tablica.length - 2];
    }

    //h
    let tmp = [...this.tablica];
    for (let i = 0; i < tmp.length; i++) {
      tmp[i] *= tmp[i];
    }

    //i
    let Parzyste = this.tablica.filter(this.parzysta);
    let NieParzyste = this.tablica.filter(this.nieparzysta);
    //j
    let podzielne_przez_3 = 0;
    for (let i = 0; i < this.tablica.length; i++) {
      if (this.tablica[i] % 3 == 0) podzielne_przez_3++;
    }
    //k
    let tab1 = [...this.tablica];
    tab1.reverse();
    this.txt =
      'Tablica = [' +
      this.tablica +
      '] min = ' +
      min +
      ' max = ' +
      max +
      ' srednia = ' +
      sr +
      ' ilosc wystapien liczby 3: ' +
      liczba3 +
      ' mediana = ' +
      mediana +
      '   \n min = ' +
      Tab_Min +
      ' max = ' +
      Tab_Max +
      ' powiekszone do kwadratu = [' +
      tmp +
      '] Liczba Przystych: ' +
      Parzyste.length +
      ' Liczba nieparzystych: ' +
      NieParzyste.length +
      ' liczba podzielnych przez 3: ' +
      podzielne_przez_3 +
      ' odwrocona kolejność: ' +
      tab1;
  }

  //5 Wyliczenie
  //tasownie tablicy
  shuffleArray(array: any[]): any[] {
    for (let i = array.length - 1; i > 0; i--) {
      let j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
  }

  enumeracja: any[] = [];
  warzywa: string[] = [];
  dodanie_warzyw(): any {
    this.warzywa.push(
      (document.getElementById('warzywo') as HTMLInputElement).value
    );
    if (this.warzywa.length == 5) {
      //b
      this.enumeracja = this.shuffleArray(this.wyliczenie());
      //c
      this.enumeracja.push(this.czy_jest('cwaniak'));
    }
  }
  wyliczenie(): any {
    let cwel = {
      warzywo1: this.warzywa[0],
      warzywo2: this.warzywa[1],
      warzywo3: this.warzywa[2],
      warzywo4: this.warzywa[3],
      warzywo5: this.warzywa[4],
    };
    return Object.values(cwel);
  }
  czy_jest(str: string): boolean {
    let items = this.wyliczenie();
    if (
      str == items[0] ||
      str == items[1] ||
      str == items[2] ||
      str == items[3] ||
      str == items[4]
    ) {
      return true;
    } else {
      return false;
    }
  }

  //6
  informacje: string = '';
  bisekcja(a: number, b: number, c: number): void {
    if (a == 0) {
      this.informacje = 'funkcja kwadratowa musi mieć a różne od 0';
      return;
    }
    let p = -b / (2 * a);
    let delta = b * b - 4 * a * c;
    if (delta < 0) {
      this.informacje = 'Brak miejsc 0';
    } else if (delta == 0) {
      this.informacje = 'Jedno miejsce 0 równe: ' + p;
    } else {
      let cos = (l: number, p: number): number => {
        let epsilon = 0.1;
        let Fl = a * l * l + b * l + c;
        let Fp = a * p * p + b * p + c;
        let licznik = 0;
        while (Math.abs(l - p) > epsilon) {
          let s = (l - p) / 2;
          let Fs = a * s * s + b * s + c;
          if (Fs == 0) {
            return s;
          } else if (Fs < 0) {
            l = s;
          } else {
            p = s;
          }
          if (licznik > 100) {
            break;
          }
          licznik++;
        }
        return (l + p) / 2;
      };
      this.informacje =
        'Pierwsze miejsce 0 to: ' +
        cos(p - 50, p) +
        ' a drugie to: ' +
        cos(p, p + 50);
    }
  }
  //7
  obwod: number = 0;
  pole: number = 0;
  rozwiaz_trapez(a: number, b: number, h: number): void {
    let wiele_wartości = (): [number, number] => {
      let p = ((a + b) * h) / 2;
      let o = a + b + 2 * Math.sqrt(Math.pow((b - a) / 2, 2) + Math.pow(h, 2));
      return [p, o];
    };
    [this.pole, this.obwod] = wiele_wartości();
  }
}
