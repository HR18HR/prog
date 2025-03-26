import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import { Observable } from 'rxjs';
import { jwtDecode } from 'jwt-decode';

export interface libro{
  id:number,
  titolo:string
};

@Injectable({
  providedIn: 'root'
})
export class LibroService {
}
