import { Injectable } from '@angular/core';
import { HttpClient,HttpHeaders} from '@angular/common/http';
import { Observable } from 'rxjs';
import { Buffer } from 'buffer';
import { ActivatedRouteSnapshot, CanActivate, GuardResult, MaybeAsync, RouterStateSnapshot } from '@angular/router';



export interface User{
  email:string;
  password:string
}


@Injectable({
  providedIn: 'root'
})
export class Userservice implements CanActivate{  //CanActivate permette di non accedere a una rotta se non se si logga l'Utente
  guardHome:boolean=false; //guard 

  constructor(public Http:HttpClient){ }

  //FUNZIONE CHE MANDA NELL HEADER USERNAME E PASSWORD CONCATENNATI CON : IN -POST-
  ACCEDI(username:string,password:string):Observable<JSON>{
     const header=new HttpHeaders({
      'Authorization':'Basic '+Buffer.from(username.concat(':').concat(password)).toString("base64")
    })
    return this.Http.post<JSON>('http://localhost:3000/login', {}, {headers:header})
   }



  //FUNZIONE CHE MANDA USERNAME E PASSWORD IN -POST- NELL'ENDPOINT /regitsrazione

  REGIST(username:string,password:string):Observable<JSON>{
    return this.Http.post<JSON>("http://localhost:3000/registrazione",{email:username,password:password},{})
  }



DAMMIALL():Observable<User[]>{
  const header=new HttpHeaders({
    'Authorization': 'Bearer '+localStorage.getItem("jwt")});
    return this.Http.get<User[]>("http://localhost:3000/email",{headers:header})
  }

//Implementazione di CanActivate e ritorna un semplice booleano
canActivate(route: ActivatedRouteSnapshot, state: RouterStateSnapshot): MaybeAsync<GuardResult> {
  return this.guardHome;
}

}


