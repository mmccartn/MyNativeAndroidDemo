package edu.usc.nsl.carma.nativecaller;

import android.util.Log;

/**
 * The NDK seems fairly restrictive in terms of what java classes may make a call
 * to the native functions since these functions must contain in their name, 
 * the name fo the java classes that are allowed to call them
 * 
 * This Native Caller is a central interface to all of the native functions written
 * for this application, as in all native function declarations contain "NativeCaller"
 * in their name.
 */
public class NativeCaller {

	private static final String DEBUG_TAG = "JAVA";
	
	// Don't make these static
	private native void helloLog(String logThis);
	private native String getString(int value1, int value2);
	private native String stringFromJNI();
	
	// The name (ndk1) of the native library is defined in the makefile
	static {
		System.loadLibrary("ndk1");
	}
	
	public NativeCaller() {
		super();
	}
	
	//c example accepting a string and making a call to the Android log util
	public void call1() {
		helloLog("This will log to LogCat via the native call.");
	}
	
	//c example doing some math and returning a string
	public void call2() {
		String result = getString(5,2);
		Log.v(DEBUG_TAG, "Result: "+result);
		result = getString(105, 1232);
		Log.v(DEBUG_TAG, "Result2: "+result);
	}
	
	//c++ example returning a string
	public void call3() {
		Log.v(DEBUG_TAG, stringFromJNI());
	}

}
