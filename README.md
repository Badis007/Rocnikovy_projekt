# Ročníkový projekt - autíčko ovládané přes wifi

Inspirace - https://www.youtube.com/watch?v=mJEftoeSBOU

tohle -> https://www.youtube.com/watch?v=gU7vlhU1HvU

# Harmonogram:
- [x] Září - objednávka součástek

- [x] Říjen - Pájení motorů, stavba podvozku

- [x] Listopad - aplikace, připojení na wifi, zapojení součástek na podvozek.

- [x] Prosinec - zpracování dokumentace.

- [ ] Leden - dokončení a doladění projektu.

# Stav projektu:
- Objednaný podvozek byl moc malý, náhrada dřevěným výřezem. 
- Sestavení autíčka doma bez podvozku, následné rozebrání pro přenos do školy, o víkendu následné sestavení na nový podvozek a nalepení     tavící pistolí. 
- vyřešení připojení na wifi.
- Sestavení celého auta do funkčního stavu.
- Úspěšně otestováno v přiloženém videu na mém githubu ve složce "stavba projektu". 
- V následujících dnech doupravím zapojení auta k lepší vizuální podobě a optimalizuju kód.
- Optimalizovaný kód, z aplikace uložena hodnota 1-5 pro každou funkci zvlášť do stringu, string se v ESP převede na int, poté je poslán      do switche pro splnění podmínek, následně vyvolána určitá funkce podle směru zmáčknutí tlačítka v aplikaci.
- Kabely FM to FM nahrazeny za napájené spoje, přidán vypínač pro lepší přehlednost a vyhnutí se stálemu vytahování baterek z holderu. 
- Kabely motorů vylepšeny a nahrazeny.



# Potřebné součástky
- 4x motorek + kolečka
- motor driver
- ESP8266
- battery holder 
- přepínač


# Odkazy: 
- ESP8266 https://navody.arduino-shop.cz/navody-k-produktum/esp8266-vyvojova-deska-wemos-d1.html
- L298N https://robotelektro.cz/moduly-sestavene?product_id=81
- Motor s převodovkou https://www.hwkitchen.cz/motor-s-prevodovkou-pro-arduino-robota/
