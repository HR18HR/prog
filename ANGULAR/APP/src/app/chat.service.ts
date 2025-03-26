import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import{io,Socket} from 'socket.io-client'
import {jwtDecode}from 'jwt-decode';

@Injectable({
  providedIn: 'root'
})
export class CHATService {
  options = {                     
    transports: ['websocket'],
    cors: {                       /*opzioni per mandare dati con socket e evitare il CORS.Anche se il mio
                                  server express ha CORS abilitato ho settato cors anche dalla parte del client 
                                   perchè senno non funzionava*/
      cors:'*', 
    }
  }

constructor() { }
So:Socket=io("http://localhost:3000",this.options);     //setto il mio socket 

}
