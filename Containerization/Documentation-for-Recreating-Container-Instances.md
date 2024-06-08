# Project 2 - Documentation for Recreating Container Instances




<img src="https://github.com/isha-kawosa/CSCE-412-CLOUD-COMPUTING/assets/149615714/7b006de0-44f8-4731-bb91-5bb6a4e58bed" width="180" height="180" align="right">

### Overview

This document serves as a guide to recreate the container orchestration environment for Project 2. It includes instructions for creating the base container and subsequent services using Docker and docker-compose.

## Recreating Container Instances

### A. Create an Ubuntu Instance on AWS

1. **Sign in to AWS Management Console:**
   - Go to the AWS Management Console.
   - Sign in with your AWS account credentials.
     
2. **Launch an EC2 Instance:**
   - In the AWS Management Console, navigate to the EC2 Dashboard.
   - Click on "Launch Instance".
   - Choose an Amazon Machine Image (AMI). Select "Ubuntu Server 20.04 LTS (HVM), SSD Volume Type".
   - Choose an Instance Type. Select "t2.micro" (eligible for free tier).
   - Configure Security Group. Create a new security group with the following inbound rules:
   - HTTP (port 80) from anywhere (0.0.0.0/0); SSH (port 22) from your IP (for security)
   - Review and Launch. Click "Launch".
   - Create New Key Pair
   - In the "Select an existing key pair or create a new key pair" section, select "Create a new key pair".
   - Enter a name for your key pair in the "Key pair name" field. For example, my-ec2-keypair.
   - Use the default RSA key type.
   - Choose .pem for the private key file format.
   - Click the "Download Key Pair" button.
   - Confirm that you have downloaded the key pair and acknowledge the warning about losing the key pair (if you lose it, you won’t be able to connect to your instance).
   - Click "Launch Instances" to complete the launch process.

3. **Access the Ubuntu Instance:**
   - Open a terminal on your local machine.
   - Navigate to the directory where your key pair file is stored.
   - Change the key file permissions to read-only:
     ```bash
     chmod 400 your-key-file.pem
     ```
   - Use SSH to connect to your instance:
     ```bash
     ssh -i path/to/your-key-pair.pem ubuntu@your-instance-ip-address
     ```

### B. Installation of Prerequisites

#### Docker Installation

1. **Update the system and install prerequisites:**
   ```bash
   sudo apt-get update
   sudo apt-get install ca-certificates curl
   sudo install -m 0755 -d /etc/apt/keyrings
   ```
2. **Add Docker’s official GPG key and repository:**
   ```bash
   sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
   sudo chmod a+r /etc/apt/keyrings/docker.asc
   echo \
     "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
     $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
     sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
   sudo apt-get update
   ```
3. **Install Docker Engine and test it:**
   ```bash
   sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
   sudo docker run hello-world

   ```
4. **Post-installation steps to run Docker without sudo:**
   ```bash
   sudo groupadd docker
   sudo gpasswd -a $USER docker
   newgrp docker
   docker run hello-world
   docker image ls
   ```

#### Docker compose Installation

1. Install Docker Compose:
   ```bash
   sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
   sudo chmod +x /usr/local/bin/docker-compose
   docker-compose --version
   ```
   
### C.  Create and Dockerize Nginx Server

1. **Prepare your Static Website:**
   - Ensure your website files are organized. Main HTML file should be named index.html
     
2. **Create a Dockerfile in your project directory:**
   ```bash
   FROM nginx:stable-alpine
   COPY . /usr/share/nginx/html
   EXPOSE 80
   CMD ["nginx", "-g", "daemon off;"]
   ```
3. **Build the Docker container image:**
   ```bash
   docker build -t my-nginx-container .
   ```
4. **Verify the created image:**
   ```bash
   docker image ls
   ```

### D.  Run and Test the Container

1. **Run the container:**
   ```bash
   docker run -p 8080:80 my-nginx-container
   ```
     
2. **Configure AWS Security Group for HTTP access:**
   - In the EC2 dashboard, select your instance.
   - Click on "Security" and then "Security Groups".
   - Add an inbound rule for HTTP (port 8080) from anywhere (0.0.0.0/0).
     
3. **Test the containerized website in a web browser:**
   -  Open your web browser and navigate to http://54.153.36.94:8080.
  
### E.  Replicate Containers using Docker Compose

1. **Create a docker-compose.yml file in your project directory:**
   ```bash
   version: '3'
   services:
     web:
       image: my-nginx-container
       ports:
         - "8080:80"
   ```
     
2. **Modify the docker-compose.yml to create 5 identical container instances:**
   ```bash
   version: '3'
   services:
     webserver1:
       image: my-nginx-container
       volumes:
         - ./websites/webserver1:/usr/share/nginx/html
       ports:
         - "8081:80"
     webserver2:
       image: my-nginx-container
       volumes:
         - ./websites/webserver2:/usr/share/nginx/html
       ports:
         - "8082:80"
     webserver3:
       image: my-nginx-container
       volumes:
         - ./websites/webserver3:/usr/share/nginx/html
       ports:
         - "8083:80"
     webserver4:
       image: my-nginx-container
       volumes:
         - ./websites/webserver4:/usr/share/nginx/html
       ports:
         - "8084:80"
     webserver5:
       image: my-nginx-container
       volumes:
         - ./websites/webserver5:/usr/share/nginx/html
       ports:
         - "8085:80"
   ```
   
3. **Run the compose file:**
   ```bash
   docker-compose up -d
   ```
4. **Verify all instances are running correctly:**
   - Check each instance by navigating to:
      http://54.153.36.94:8081
      http://54.153.36.94:8082
      http://54.153.36.94:8083
      http://54.153.36.94:8084
      http://54.153.36.94:8085

### F.  Create Unique Container Copies

1. **Modify the base container to create 5 unique instances:**
   - Create separate directories for each instance, e.g., web1, web2, web3, web4, web5.
   - Modify the content in each directory to be unique.
     
2. **Create Dockerfiles in each directory:**
   ```bash
   FROM nginx:stable-alpine
   COPY . /usr/share/nginx/html
   EXPOSE 80
   CMD ["nginx", "-g", "daemon off;"]
   ```
3. **Build and run each unique container:**
   ```bash
   docker build -t web1-container ./web1
   docker build -t web2-container ./web2
   docker build -t web3-container ./web3
   docker build -t web4-container ./web4
   docker build -t web5-container ./web5
   
   docker run -p 8081:80 web1-container
   docker run -p 8082:80 web2-container
   docker run -p 8083:80 web3-container
   docker run -p 8084:80 web4-container
   docker run -p 8085:80 web5-container
   ```
4. **Test each unique container:**
   - Open your web browser and navigate to the corresponding URLs.
