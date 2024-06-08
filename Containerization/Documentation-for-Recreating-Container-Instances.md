# Project 2 - Documentation for Recreating Container Instances



<img src="https://github.com/isha-kawosa/CSCE-412-CLOUD-COMPUTING/assets/149615714/7b006de0-44f8-4731-bb91-5bb6a4e58bed" width="200" height="200" align="right">

### Overview

This document serves as a guide to recreate the container orchestration environment for Project 2. It includes instructions for creating the base container and subsequent services using Docker and docker-compose.

## Recreating Container Instances

### A. Create an Ubuntu Instance on AWS

1. **Launch an EC2 Instance:**
   - Go to the AWS Management Console.
   - Navigate to the EC2 Dashboard and launch a new instance.
   - Select the Ubuntu Server 20.04 LTS AMI (Amazon Machine Image).
   - Choose an instance type (t2.micro is free-tier eligible).
   - Configure the instance and security group to allow SSH (port 22) and HTTP (port 80) access.
   - Launch the instance and download the key pair for SSH access.

2. **Connect to Your Instance:**
   - Use SSH to connect to your instance:
     ```bash
     ssh -i path/to/your-key-pair.pem ubuntu@your-instance-ip-address
     ```

### B. Installation of Prerequisites

#### Docker Installation

1. **Update your package index:**
   ```bash
   sudo apt-get update
