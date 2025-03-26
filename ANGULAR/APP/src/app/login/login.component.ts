import { Component,AfterViewChecked,DoCheck} from '@angular/core';
import { Router, RouterLink, RouterOutlet} from '@angular/router';
import {FormsModule} from '@angular/forms'
import { Userservice } from '../User.service';
import { NgIf } from '@angular/common';
import {io,Socket} from 'socket.io-client'
@Component({
  selector: 'app-login',
  imports: [FormsModule,NgIf],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent{
  guard:boolean=false;
  username:string='';  
  password:string='';  
  Errore:{message:string,tentativi:number}={message:'',tentativi:0};
  benvenuto:string='';
  chat:string='lo';
  constructor(public SerH:Userservice,public Rotta:Router){}
  //FUNZIONE ACCEDI PER GESTIRE L'AUTENTICAZIONE DELL'USER 
  ACCEDI():void{
    this.SerH.ACCEDI(this.username,this.password).subscribe({
      next:data=>{
        this.benvenuto=JSON.parse(JSON.stringify(data)).message='Benvenuto';
        localStorage.setItem("jwt",JSON.parse(JSON.stringify(data)).toke);
        this.SerH.guardHome=true;
        console.log(this.SerH.guardHome);
        this.Rotta.navigate(['/home']);
      },
      error:err=>{
        if(err.status==401){this.Errore.message="Credenziali non valide",this.Errore.tentativi=1
          setTimeout(()=>{this.Errore.tentativi=0},2000)
        }
        else{
          this.Errore.message="Errore Riprova più Tardi",this.Errore.tentativi=1;
          setTimeout(()=>{this.Errore.tentativi=0},2000)
        }
      }
  })
  }

  //GUARD OF ROUTE


  INDI(){
    this.Rotta.navigate(["/registrazione"]);
  }

}

