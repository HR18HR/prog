import { Routes } from '@angular/router';
import { AppComponent } from './app.component';
import { RegistrazioneComponent } from './registrazione/registrazione.component';
import { LoginComponent } from './login/login.component';
import { HOMEComponent } from './home/home.component';
import { Userservice } from './User.service';

export const routes: Routes = [ 
   { path: '',loadComponent: () => import('./app.component').then(m => m.AppComponent),pathMatch:'full',canActivate:[AppComponent]},
    {path:'login',loadComponent: () => import('./login/login.component').then(m => m.LoginComponent)} ,//login route
    { path: 'registrazione',loadComponent: () => import('./registrazione/registrazione.component').then(m => m.RegistrazioneComponent)}, // Registration route// Default route
    { path: 'home',loadComponent: () => import("./home/home.component").then(m => m.HOMEComponent),canActivate:[Userservice]}
  ];
