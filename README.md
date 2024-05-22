<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Instagram][ig-shield]][ig-url]
[![PCBWAY][sponsor-shield]][sponsor-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://makingdevices.com/links/">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Making Devices</h3>

  <p align="center">
    Open Source projects where we struggle with engineering, electronics, coding and who knows what else... Pic Bytes Micro is a 8-bit console based in the PIC18F4550 with an analog LED matrix as the screen.
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#Build-one">Build one</a>
      <ul>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#Sponsor">Sponsor</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Bytes Counter Shot][product-screenshot]](https://makingdevices.com/PicBytesMicro)

Pic Bytes Micro was born to explore the capabilities of C language inside the PIC18F4550, as I wanted to test if the 8bit microcontroller was able to run some old games such tetris, snake or arkanoid. To maintain the old-fashion look of the project, the screen is made by 16x10 matrix of LEDs, controlled by individual transistors and the IO pins of the PIC. In addition, sounds and a rechargable battery will be added to the device.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

[![Microcontroller][PIC]][PIC-url]
[![MPLAB C][MPLAB-C]][MPLAB-C-url]
[![Kicad][kicad-shield]][kicad-url]
[![SPONSOR][sponsor-icon]][sponsor-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Build one
The project is finished and no further development will be made. The device is safe, stable and It was tested. 

1. Get the gerber files for the latest version: [V1.25](/Gerber/PicBytesMicroV1.25.zip) 
2. Send them to a PCB manufacturer ([Our Sponsor is PCBWAY][sponsor-url])
3. You can read the [schematics](/output_files/PicBytesMicro_schematic_V1.25.pdf) 
4. [The firmware is available on the repo](/Simulation%26Firmware) 
5. For most of the components, you can reach to [Würth Elektronik, our sponsor for electronic components](https://www.we-online.com/en) 

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

Instructions of use:

- When turn on, a menu is shown to select between the available games.
- Once you have played a game, a score board will appear everytime you open the game.
- You have a setting menu to turn-off the init splash and the sound.
- If you leave the console one minute without touching the buttons, it will turn into sleep mode.
- Enjoy!

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] Solder the prototype
- [x] Test the LCD of the prototype
- [x] Design a PCB
  - [x] Add rechargeable battery
  - [x] Add USB communication if possible.
  - [x] Add sound control with the buzzers
  - [x] Develop Snake game
  - [x] Develop Tetris game
  - [x] Develop Arkanoid game
  - [x] Score board
  - [x] Sleep Mode
- [x] Validate the design


See the [open issues](https://github.com/makingdevices/PicBytesMicro/issues) for a full list of proposed features (and known issues).

State: Project <b>FINISHED</b> - 22/05/2024

Priority: <b>Medium</b>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under three licenses:
- [Hardware](/License/HW_cern_ohl_s_v2.pdf)
- [Software](/License/SW_GPLv3.0.txt)
- [Documentation](/License/Documentation_CC-BY-SA-4.0.txt)

[![GPL v3 License][license-shield]][license-url] 
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Making Devices - [@MakingDevices](https://www.instagram.com/makingdevices/)

Project Link: [https://github.com/makingdevices/PicBytesMicro](https://github.com/makingdevices/PicBytesMicro/)

Other Links: [LinkTree](https://makingdevices.com/links/)

<!-- Sponsor -->
## Sponsor - PCBWAY

[PCBWAY](https://www.pcbway.com/?from=makingdevices) is the most professional PCB manufacturer for prototyping and low-volume production to work with in the world. With more than a decade in the field, They are committed to meeting the needs of their customers from different industries in terms of quality, delivery, cost-effectiveness and any other demanding requests. As Sponsor of Making Devices, they will be in charge of all the PCBs for MDV, allowing both of us to grow together in a long term partnership. We hope you take them into account for your both personal and professional prototypes or products.

[![Sponsor Shot][sponsor-pcb-1]][sponsor-url]
[![Sponsor Shot][sponsor-pcb-2]][sponsor-url]

## Sponsor - Würth Elektronik

[Wurth Elektronik](https://www.we-online.com/en) is one of the leading manufacturers of electronic and electromechanical components. The best I can say about them is to show you some pictures: All the LEDs from the board are from them. They also have buttons, resistors and capacitors that we use in all our PCBs. They also have some design kits with a lifetime refill which are amazing for makers and business so you can prototype on the go with a huge variety of components!

[![Sponsor Shot][sponsor-wurth-1]][sponsor-url-wurth]
[![Sponsor Shot][sponsor-wurth-3]][sponsor-url-wurth]


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/makingdevices/PicBytesMicro.svg?style=for-the-badge
[contributors-url]: https://github.com/makingdevices/PicBytesMicro/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/makingdevices/PicBytesMicro.svg?style=for-the-badge
[forks-url]: https://github.com/makingdevices/PicBytesMicro/network/members
[stars-shield]: https://img.shields.io/github/stars/makingdevices/PicBytesMicro.svg?style=for-the-badge
[stars-url]: https://github.com/makingdevices/PicBytesMicro/stargazers
[issues-shield]: https://img.shields.io/github/issues/makingdevices/PicBytesMicro.svg?style=for-the-badge
[issues-url]: https://github.com/makingdevices/PicBytesMicro/issues
[license-shield]: /images/license.png
[license-url]: https://github.com/makingdevices/PicBytesMicro/tree/main/License
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/company/making-devices/
[sponsor-shield]: https://img.shields.io/badge/SPONSOR-PCBWAY-black.svg?style=for-the-badge&colorB=1200
[sponsor-url]: https://www.pcbway.com/?from=makingdevices
[sponsor-screenshot]: /images/PCB_sponsor.png
[sponsor-pcb-1]: /images/picbytesmicro_pcb1.jpg
[sponsor-pcb-2]: /images/picbytesmicro_pcb2.jpg
[sponsor-wurth-1]: /images/wurth_1.jpg
[sponsor-wurth-3]: /images/wurth_3.jpg
[sponsor-url-wurth]: https://www.we-online.com/en
[product-screenshot]: images/screenshot.jpg
[PIC]: https://img.shields.io/badge/PIC18LF4550-000000?style=for-the-badge
[PIC-url]: https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/39632e.pdf
[kicad-shield]: https://img.shields.io/badge/kicad-0b03fc?style=for-the-badge&logo=kicad&logoColor=white
[kicad-url]: https://www.kicad.org/
[YT-screenshot]: images/YT_assembly.PNG
[sponsor-icon]:  https://img.shields.io/badge/-PCBWAY-black.svg?style=for-the-badge&colorB=1200
[ig-shield]: https://img.shields.io/badge/instagram-a83297?style=for-the-badge&logo=instagram&logoColor=white
[ig-url]: https://www.instagram.com/makingdevices/
[MPLAB-C]: https://img.shields.io/badge/MPLAB%20C18-DD0031?style=for-the-badge&logo=C&logoColor=white
[MPLAB-C-url]: https://www.microchip.com/en-us/development-tool/SW006011
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
