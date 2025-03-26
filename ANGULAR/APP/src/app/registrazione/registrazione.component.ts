import { Component } from '@angular/core';
import { Userservice } from '../User.service'; 
import { FormsModule } from '@angular/forms';
import { error } from 'console';
import { NgIf } from '@angular/common';
import { Router } from '@angular/router';
@Component({
  selector: 'app-registrazione',
  imports: [FormsModule,NgIf],
  templateUrl: './registrazione.component.html',
  styleUrl: './registrazione.component.css'
})
export class RegistrazioneComponent {
  username:string='';
  password:string='';
  risposta:string='';
  res:{Pos:number,Neg:number}={Pos:0,Neg:0};
  constructor(public UserH:Userservice,public Router:Router){}

  //FUNZIONE  PER REGISTRARE NUOVO USER 
  Regist(){
    this.UserH.REGIST(this.username,this.password).subscribe({
      next:data=>{this.risposta=JSON.parse(JSON.stringify(data)).message;this.res.Pos=1;
      this.Router.navigate(["/login"]);
      setTimeout(()=>{this.res.Pos=0},3000)
    },

      error:err=>{this.risposta=this.ERR(err),this.res.Neg=1;setTimeout(()=>{this.res.Neg=0},3000)}
    })
    
  }

//FUNZIONE GESTIONE ERRORE
ERR(err:any):string{
  if(err?.status==500)return "Credenziali già Usate ";
  else return "Errore Riprovare più tardi";
}

}
