import { TestBed } from '@angular/core/testing';

import { CHATService } from './chat.service';

describe('CHATService', () => {
  let service: CHATService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(CHATService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
