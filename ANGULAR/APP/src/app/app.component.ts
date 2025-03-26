import { Component,AfterViewInit} from '@angular/core';
import { Router, RouterLink, RouterOutlet,CanActivate, ActivatedRouteSnapshot, GuardResult, MaybeAsync, RouterStateSnapshot,} from '@angular/router';
import  {NgIf} from '@angular/common'
@Component({
  selector: 'app-root',
  imports: [RouterOutlet,NgIf],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent implements CanActivate{
  clicked:boolean=false;
  view:boolean=false
  constructor(public Route:Router){}
  Login(){
    this.Route.navigate(['/login'])
    this.clicked=true
  }

  Regis(){
    this.Route.navigate(["/registrazione"])
    this.clicked=true
  }

canActivate(route: ActivatedRouteSnapshot, state: RouterStateSnapshot): MaybeAsync<GuardResult> {
  return this.view;
}
DELETE(){
  localStorage.removeItem("jwt");
}

ngAfterViewInit(){
window.addEventListener("beforeunload",()=>{
  localStorage.removeItem("jwt");
})
}
}
