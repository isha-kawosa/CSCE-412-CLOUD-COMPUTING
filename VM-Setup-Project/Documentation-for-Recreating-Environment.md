# Virtual Machine Creation Guide for IT Personnel



<img src="https://github.com/isha-kawosa/CSCE-412-CLOUD-COMPUTING/assets/149615714/7b006de0-44f8-4731-bb91-5bb6a4e58bed" width="150" height="150" align="right">

## Overview
This document provides detailed instructions for creating a virtual machine (VM) suitable for a development environment. The VM will be used for software development and documentation design, equipped with necessary tools and software. The objective is to create a repeatable process for IT personnel to recreate this environment.

## Step 1: Set Up AWS Lightsail Account

### Create an AWS Account
1. Go to the [AWS Lightsail website](https://aws.amazon.com/lightsail/).
2. Sign up for an AWS account using your email.
3. Log in to the AWS Management Console.

### Navigate to Lightsail
1. In the AWS Management Console, type "Lightsail" in the search bar and select it.

## Step 2: Create a Virtual Machine (VM)

### Create an Instance
1. Click on "Create instance".
2. Select your region (choose one close to you or the target users).

### Choose Your Platform
1. Under "Select a platform", choose "Microsoft Windows".
   
### Choose Your Blueprint
1. Under "Select a blueprint", choose "OS Only".
2. Select "Windows Server 2019".

### Choose Your Instance Plan
1. Select the Dual-stack network type.
2. Select a size with 3 month trial.
   
### Name Your Instance
1. Give your instance a recognizable name.

### Launch Instance
1. Click on "Create instance".

## Step 3: Configure the VM

### Access Your Instance
1. Once the instance is running, click on the instance name to view details.
2. Click "Connect using RDP" to download the Remote Desktop Protocol file or you can use the browser version.
3. Use the RDP file to connect to your instance. Enter the default username (Administrator) and password (find this in the instance details).

### Install Required Software

1. **Google Chrome**: Download and install from [Google Chrome](https://www.google.com/chrome/).
   
   Then, using Google Chrome, install the following:
   
   Code Editor:
   - **Notepad++**: Download and install from [Notepad++](https://notepad-plus-plus.org/downloads/).
   
   Compiler:
   - **MinGW Compiler**: Download and install from [MinGW](https://sourceforge.net/projects/mingw/).
   
   Integrated Development Environment (IDE):
   - **Visual Studio Installer**: Download from [Visual Studio Installer](https://visualstudio.microsoft.com/downloads/).
   
   Document Editor:
   - **LibreOffice**: Download and install from [LibreOffice](https://www.libreoffice.org/download/download/).
   
   PDF Viewer:
   - **Adobe Acrobat Reader**: Download and install from [Adobe Acrobat Reader](https://get.adobe.com/reader/).

### Software Installation Instructions

#### Install Notepad++
1. Open the [Notepad++ download page](https://notepad-plus-plus.org/downloads/).
2. Download the installer for Windows.
3. Run the installer and follow the on-screen instructions.

#### Install MinGW (Compiler)
1. Open the [MinGW download page](https://sourceforge.net/projects/mingw/).
2. Download the installer.
3. Run the installer and follow the on-screen instructions to install the GCC compiler.

#### Install Visual Studio Installer
1. Open the [Visual Studio Installer download page](https://visualstudio.microsoft.com/downloads/).
2. Download the installer for Windows.
3. Run the installer and follow the on-screen instructions to install Visual Studio.

#### Install LibreOffice (Document Editor)
1. Open the [LibreOffice download page](https://www.libreoffice.org/download/download/).
2. Download the installer for Windows.
3. Run the installer and follow the on-screen instructions.

#### Install Adobe Acrobat Reader (PDF Viewer)
1. Open the [Adobe Acrobat Reader download page](https://get.adobe.com/reader/).
2. Download the installer for Windows.
3. Run the installer and follow the on-screen instructions.

